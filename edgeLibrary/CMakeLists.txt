cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(EDGE_CONNECTOR_LIBRARY CXX)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/ExternalLibs/Modules")

find_package(libcrypto++)

set (INC_DIRS src/hmac)

set(SRC src/hmac/hmacmanager.cpp)

set(HDR src/hmac/hmacmanager.hpp) 

add_library(edge_connector_library SHARED ${SRC} ${HDR})

target_include_directories(edge_connector_library PUBLIC ${INC_DIRS})