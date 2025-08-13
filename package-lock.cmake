# CPM Package Lock
# This file should be committed to version control

# enet
CPMDeclarePackage(enet
  VERSION 1.3.18
  GITHUB_REPOSITORY lsalzman/enet
  SYSTEM YES
  EXCLUDE_FROM_ALL YES
)
# lmdb (unversioned)
# CPMDeclarePackage(lmdb
#  NAME lmdb
#  GIT_TAG LMDB_0.9.31
#  DOWNLOAD_ONLY YES
#  GITHUB_REPOSITORY LMDB/lmdb
#)
# Ccache.cmake
CPMDeclarePackage(Ccache.cmake
  VERSION 1.2.5
  GITHUB_REPOSITORY TheLartians/Ccache.cmake
  SYSTEM YES
  EXCLUDE_FROM_ALL YES
)
