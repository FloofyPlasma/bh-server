if((UNIX AND NOT APPLE) OR WIN32) # I believe these are required for both Linux and Windows builds, 
                                  # but definitely not macOS builds.
add_subdirectory(GLKit)

target_include_directories(${PROJECT_NAME} PRIVATE
    blockheads
    GLKit
)

endif()
