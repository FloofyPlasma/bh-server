include(cmake/CPM.cmake)
CPMUsePackageLock(package-lock.cmake)

function(bhServer_setup_dependencies)

    if (NOT TARGET enet)
        cpmaddpackage("gh:lsalzman/enet@1.3.18")
    endif ()

    if (NOT TARGET lmdb)
        cpmaddpackage(
                NAME lmdb
                GITHUB_REPOSITORY LMDB/lmdb
                GIT_TAG "LMDB_0.9.31"
                DOWNLOAD_ONLY YES
        )

        add_library(lmdb STATIC
                ${lmdb_SOURCE_DIR}/libraries/liblmdb/mdb.c
                ${lmdb_SOURCE_DIR}/libraries/liblmdb/midl.c
        )

        target_include_directories(lmdb PUBLIC
                ${lmdb_SOURCE_DIR}/libraries/liblmdb
        )
    endif ()

    if (NOT TARGET yaGetopt)
        cpmaddpackage(
                NAME yaGetopt
                GITHUB_REPOSITORY kubo/ya_getopt
                GIT_TAG "6ce431085b81d9bb8639ed2f858c4f4fbc3ab988"
                DOWNLOAD_ONLY YES
        )

        add_library(yaGetopt STATIC
                ${yaGetopt_SOURCE_DIR}/ya_getopt.c
        )

        target_include_directories(yaGetopt PUBLIC
                ${yaGetopt_SOURCE_DIR}
        )
    endif ()

    cpmaddpackage("gh:TheLartians/Ccache.cmake@1.2.5")

endfunction()
