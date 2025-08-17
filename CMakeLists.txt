cmake_minimum_required(VERSION 3.29)
project(BlockheadsServer
        VERSION 0.0.1
        DESCRIPTION "Blockheads Server Decompilation Project"
        HOMEPAGE_URL "https://floofyplasma.github.io/bh-server/"
        LANGUAGES C CXX OBJC OBJCXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(USE_CCACHE ON)

# Dependencies
include(Dependencies.cmake)
bhServer_setup_dependencies()

add_executable(${PROJECT_NAME})
add_subdirectory(src)

# GNUstep (UNIX non-Apple)
if(UNIX AND NOT APPLE)
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
    separate_arguments(GNUSTEP_OBJC_FLAGS_LIST NATIVE_COMMAND "${GNUSTEP_OBJC_FLAGS}")
    separate_arguments(GNUSTEP_BASE_LIBS_LIST NATIVE_COMMAND "${GNUSTEP_BASE_LIBS}")
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<COMPILE_LANGUAGE:OBJC,OBJCXX>:${GNUSTEP_OBJC_FLAGS_LIST}>
    )
    target_link_libraries(${PROJECT_NAME} PRIVATE
        ${GNUSTEP_BASE_LIBS_LIST}
        objc
        dispatch
        enet
        lmdb
        yaGetopt
    )
endif()

# Windows
if(WIN32)
    set(GNUSTEP_ROOT "C:/GNUstep" CACHE PATH "Path to GNUstep root")

    target_include_directories(${PROJECT_NAME} PRIVATE
        $<IF:$<CONFIG:Debug>,${GNUSTEP_ROOT}/x64/Debug/include,${GNUSTEP_ROOT}/x64/Release/include>
    )
    target_link_directories(${PROJECT_NAME} PRIVATE
        $<IF:$<CONFIG:Debug>,${GNUSTEP_ROOT}/x64/Debug/lib,${GNUSTEP_ROOT}/x64/Release/lib>
    )

    target_compile_options(${PROJECT_NAME} PRIVATE
        -fobjc-runtime=gnustep-2.2
        -Xclang -fexceptions
        -Xclang -fobjc-exceptions
        -fblocks
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

    # Copy required DLLs after build, using config-aware paths and generator expressions
    set(GNUSTEP_DLLS
        objc.dll
        gnustep-base-1_31.dll
        dispatch.dll
        libiconv.dll
        libcurl$<$<CONFIG:Debug>:-d>.dll
    )
    
    foreach(DLL IN ITEMS
        objc.dll
        gnustep-base-1_31.dll
        dispatch.dll
        libiconv.dll
        libcurl$<$<CONFIG:Debug>:-d>.dll
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${GNUSTEP_ROOT}/x64/$<CONFIG>/bin/${DLL}
                $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
    endforeach()
endif()

# macOS
if(APPLE)
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
endif()
