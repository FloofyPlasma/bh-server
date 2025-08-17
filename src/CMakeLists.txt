add_subdirectory(Linux)
add_subdirectory(Mac)
add_subdirectory(SharedSource)

target_include_directories(${PROJECT_NAME} PRIVATE
    SharedSource
)
