cmake_minimum_required (VERSION 3.5.1)
project (CalcEngine)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++-8)


SET(ENGINE_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/Engine/)
SET(TEST ${CMAKE_CURRENT_SOURCE_DIR}/Test/)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/")

add_subdirectory(${ENGINE_INCLUDES})
add_subdirectory(${TEST})

INCLUDE( ./exe.cmake)

#EOF
