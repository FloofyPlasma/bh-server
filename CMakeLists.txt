cmake_minimum_required(VERSION 3.29)
project(BlockheadsServer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(GNUSTEP_ROOT "C:/GNUstep") # Bad hard code!!11
elseif(APPLE)
    message(STATUS "Building for macOS with native Objective-C runtime.")
elseif(UNIX)
    message(FATAL "Building on Linux is currently not supported. Add it in a PR if you manage to get it working :)")
endif()

if(WIN32)
    include_directories(
        ${GNUSTEP_ROOT}/x64/Debug/include
        ${GNUSTEP_ROOT}/x64/Release/include
    )

    link_directories(
        ${GNUSTEP_ROOT}/x64/Debug/lib
        ${GNUSTEP_ROOT}/x64/Release/lib
    )
endif()

set(SOURCE_FILES src/Mac/BlockheadsServer/blockheads_server/main.mm)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include_directories(
    src/Linux
    src/Linux/blockheads
    src/Mac/BlockheadsServer/blockheads_server
    src/Mac/blockheadsServer/BlockheadsServer
    src/SharedSource)

if(WIN32)
    target_compile_options(${PROJECT_NAME} PRIVATE
        -fobjc-runtime=gnustep-2.0
        -Xclang -fexceptions
        -Xclang -fobjc-exceptions
        -fblocks
        -Xclang -fobjc-arc
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
    )

    set(CMAKE_CXX_COMPILER "clang++")
    set(CMAKE_C_COMPILER "clang")

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fobjc-runtime=gnustep-2.0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-runtime=gnustep-2.0")

    # FUCING HATE WORKING WITH WINDOWS SOMETIMES LOL

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${GNUSTEP_ROOT}/x64/Debug/bin/objc.dll
        ${CMAKE_BINARY_DIR}/objc.dll
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${GNUSTEP_ROOT}/x64/Debug/bin/gnustep-base-1_31.dll
        ${CMAKE_BINARY_DIR}/gnustep-base-1_31.dll
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${GNUSTEP_ROOT}/x64/Debug/bin/dispatch.dll
        ${CMAKE_BINARY_DIR}/dispatch.dll
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${GNUSTEP_ROOT}/x64/Debug/bin/libiconv.dll
        ${CMAKE_BINARY_DIR}/libiconv.dll
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${GNUSTEP_ROOT}/x64/Debug/bin/libcurl-d.dll
        ${CMAKE_BINARY_DIR}/libcurl-d.dll
    )
elseif(APPLE)
    message(STATUS "Using native macOS Objective-C runtime.")
    
    target_link_libraries(${PROJECT_NAME}
        "-framework Foundation"
        "-framework Cocoa"
    )

    set(CMAKE_CXX_COMPILER "clang++")
    set(CMAKE_C_COMPILER "clang")

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fobjc-runtime=macosx")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-runtime=macosx")

endif()
