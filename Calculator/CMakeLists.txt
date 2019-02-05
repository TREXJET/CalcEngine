cmake_minimum_required (VERSION 3.5.1)
project (CalcEngine)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++-8)


SET(ENGINE_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/../Engine/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../build/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../build/")

INCLUDE_DIRECTORIES(
        ${ENGINE_INCLUDES}
)

#set(CALC_LIBRARY_DEPENDENCIES
#        libEngine.so
#)

INCLUDE( ./exe.cmake)

#EOF
