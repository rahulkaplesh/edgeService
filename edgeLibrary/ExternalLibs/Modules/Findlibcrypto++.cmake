# - Find libcrypto++
# Find libcrypto library.
# Once done this will define
#
#  libcrypto++_INCLUDE_DIR    - where to find libcrypto++ header files, etc.
#  libcrypto++_FOUND          - True if libcrypto++ found.

if(NOT EXISTS "${libcrypto++_INCLUDE_DIR}")
    find_path(libcrypto++_INCLUDE_DIR NAMES crypt.h HINTS ${CMAKE_SOURCE_DIR}/external/libssh2)
endif()

# handle the QUIETLY and REQUIRED arguments and set libcrypto++_FOUND to TRUE if
# all listed variables are TRUE
if(EXISTS "${libcrypto++_INCLUDE_DIR}")
    include(FindPackageHandleStandardArgs)
    mark_as_advanced(libcrypto++_INCLUDE_DIR)
endif()

if(EXISTS "${libcrypto++_INCLUDE_DIR}")
    set(libcrypto++_FOUND 1)
else()
    message(FATAL_ERROR "Unable to find libcrypto++")
    set(libcrypto++_FOUND 0)
endif()