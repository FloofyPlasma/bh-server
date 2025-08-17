cmake_minimum_required(VERSION 3.29)
include(FetchContent)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(USE_CCACHE ON)

project(BlockheadsServer
        VERSION 0.0.1
        DESCRIPTION "Blockheads Server Decompilation Project"
        HOMEPAGE_URL "https://floofyplasma.github.io/bh-server/"
        LANGUAGES C CXX OBJC OBJCXX
)

# Dependencies
include(Dependencies.cmake)
bhServer_setup_dependencies()

# GNUstep configuration (non-Apple UNIX)
if (UNIX AND NOT APPLE)
    find_program(GNUSTEP_CONFIG_EXECUTABLE gnustep-config REQUIRED)

    execute_process(
            COMMAND ${GNUSTEP_CONFIG_EXECUTABLE} --objc-flags
            OUTPUT_VARIABLE GNUSTEP_OBJC_FLAGS
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    execute_process(
            COMMAND ${GNUSTEP_CONFIG_EXECUTABLE} --base-libs
            OUTPUT_VARIABLE GNUSTEP_BASE_LIBS
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    string(REPLACE " " ";" GNUSTEP_OBJC_FLAGS_LIST "${GNUSTEP_OBJC_FLAGS}")
endif ()

add_executable(${PROJECT_NAME})
add_subdirectory(src)

# Platform-specific settings
if (WIN32)
    set(GNUSTEP_ROOT "C:/GNUstep") # TODO: Remove hardcoded path

    target_include_directories(${PROJECT_NAME} PRIVATE
            ${GNUSTEP_ROOT}/x64/Debug/include
            ${GNUSTEP_ROOT}/x64/Release/include
    )
    link_directories(
            ${GNUSTEP_ROOT}/x64/Debug/lib
            ${GNUSTEP_ROOT}/x64/Release/lib
    )

    target_compile_options(${PROJECT_NAME} PRIVATE
            -fobjc-runtime=gnustep-2.2
            -Xclang -fexceptions
            -Xclang -fobjc-exceptions
            -fblocks
            -Xclang
            -DGNUSTEP
            -DGNUSTEP_WITH_DLL
            -DGNUSTEP_RUNTIME=1
            -D_NONFRAGILE_ABI=1
            -D_NATIVE_OBJC_EXCEPTIONS
    )
    target_link_libraries(${PROJECT_NAME}
            gnustep-base
            objc
            dispatch
            enet
            lmdb
            yaGetopt
    )

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fobjc-runtime=gnustep-2.2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-runtime=gnustep-2.2")

    foreach (DLL
            objc.dll
            gnustep-base-1_31.dll
            dispatch.dll
            libiconv.dll
            libcurl-d.dll
    )
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${GNUSTEP_ROOT}/x64/Debug/bin/${DLL}
                ${CMAKE_BINARY_DIR}/${DLL}
        )
    endforeach ()

elseif (APPLE)
    target_link_libraries(${PROJECT_NAME}
            "-framework Foundation"
            "-framework Cocoa"
            enet
            lmdb
            yaGetopt
    )

    target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<COMPILE_LANGUAGE:OBJC,OBJCXX>:-fobjc-runtime=macosx>
    )
elseif (UNIX AND NOT APPLE)
    target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:OBJC,OBJCXX>:${GNUSTEP_OBJC_FLAGS_LIST}>)
    target_link_libraries(${PROJECT_NAME}
            ${GNUSTEP_BASE_LIBS}
            objc
            dispatch
            enet
            lmdb
            yaGetopt
    )
endif ()
