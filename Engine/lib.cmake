SET( LIB_NAME EngineLib )

# library source files 
SET( LIB_SRCS
    Engine.cpp
    Divider.cpp
    Multiplier.cpp
    EngineFactory.cpp
)

ADD_LIBRARY(${LIB_NAME} SHARED
${LIB_SRCS}
)

INSTALL(TARGETS ${LIB_NAME} DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

#EOF
