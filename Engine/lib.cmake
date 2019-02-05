SET( LIB_NAME EngineLib )
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++-8)


# add library source files here
SET( LIB_SRCS
    Engine.cpp
    Divider.cpp
    Multiplier.cpp
    EngineFactory.cpp
)

ADD_LIBRARY(${LIB_NAME} SHARED
${LIB_SRCS}
)

INSTALL(TARGETS ${LIB_NAME} DESTINATION ${CMAKE_BINARY_DIR}/build/)

#EOF
