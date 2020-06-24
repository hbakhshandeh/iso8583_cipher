
project(libcipher)

file(GLOB libcipher_src ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(${PROJECT_NAME} ${libcipher_src})
add_library(lib::cipher ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE lib::tools)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc) 
