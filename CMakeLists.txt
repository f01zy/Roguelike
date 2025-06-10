cmake_minimum_required(VERSION 3.10)
project(walker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

configure_file(
  "${CMAKE_SOURCE_DIR}/src/PathConfig.hpp.in"
  "${CMAKE_SOURCE_DIR}/src/PathConfig.hpp"
)

add_subdirectory(src)
