cmake_minimum_required (VERSION 3.12)
project (iso8583_cipher VERSION 1.0.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_subdirectory(tools)
add_subdirectory(cipher)
add_subdirectory(test)
