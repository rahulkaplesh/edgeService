cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 17)

project(EDGE_CONNECTOR_LIBRARY CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/ExternalLibs/Modules")

find_package(libcrypto++)
add_subdirectory(googletest)

find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)

set (INC_DIRS src/hmac
              src/restmanager)

set(SRC src/hmac/hmacmanager.cpp
        src/restmanager/restmanager.cpp)

set(HDR src/hmac/hmacmanager.hpp
        src/restmanager/restmanager.hpp) 

add_library(edge_connector_library SHARED ${SRC} ${HDR})

target_include_directories(edge_connector_library PUBLIC ${INC_DIRS})

target_link_libraries(edge_connector_library PUBLIC ssl crypto++ Qt5::Core Qt5::Network)

set(TEST_SRC test.cpp
             test/hmac/hmac_test.cpp)

add_executable(lib_test ${TEST_SRC})

target_include_directories(lib_test PUBLIC googletest/googletest/include)

add_test(NAME lib_test COMMAND lib_test gtest)

target_link_libraries(lib_test PUBLIC gtest edge_connector_library)