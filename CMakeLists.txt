cmake_minimum_required (VERSION 3.12)
project (iso8583_cipher VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

enable_testing()
add_subdirectory(gtest)

add_subdirectory(tools)
add_subdirectory(cipher)
add_subdirectory(test)
