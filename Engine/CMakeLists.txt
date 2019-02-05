#move cmake min required and compiler settings to top level?
cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++-8)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../build/")

LINK_DIRECTORIES(
${THIS_BINARY_DIR}/lib
)

INCLUDE_DIRECTORIES(
${THIS_BINARY_DIR}/
)

INCLUDE( ./lib.cmake )
#EOF
