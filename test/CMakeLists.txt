
project(iso8583_cipher_test)

file(GLOB unit_test_src ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${unit_test_src})

target_link_libraries(${PROJECT_NAME} PRIVATE lib::cipher lib::tools)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC pthread gtest)