add_subdirectory(BlockheadsServer)
add_subdirectory(blockheads_server)

target_include_directories(${PROJECT_NAME} PRIVATE
    BlockheadsServer
    blockheads_server
)
