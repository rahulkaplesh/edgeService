cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 17)

project(EDGE_CONNECTOR_LIBRARY CXX)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/ExternalLibs/Modules")

find_package(libcrypto++)
add_subdirectory(googletest)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (INC_DIRS src/hmac)

set(SRC src/hmac/hmacmanager.cpp)

set(HDR src/hmac/hmacmanager.hpp) 

add_library(edge_connector_library SHARED ${SRC} ${HDR})

target_include_directories(edge_connector_library PUBLIC ${INC_DIRS})

target_link_libraries(edge_connector_library PUBLIC ssl crypto++)

set(TEST_SRC test.cpp
             test/hmac/hmac_test.cpp)

add_executable(lib_test ${TEST_SRC})

target_include_directories(lib_test PUBLIC googletest/googletest/include)

add_test(NAME lib_test COMMAND lib_test gtest)

target_link_libraries(lib_test PUBLIC gtest edge_connector_library)