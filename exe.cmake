SET( CALC_EXE 
        calc 
)


SET( CALC_SRCS 
    Calculator/Calc.cpp
)

ADD_EXECUTABLE(
        ${CALC_EXE} 
        ${CALC_SRCS}
)

INCLUDE_DIRECTORIES(
        ${ENGINE_INCLUDES}
)

TARGET_LINK_LIBRARIES(
        ${CALC_EXE} 
        # TODO set this binary location in the top level cmake
        # so the output binary path can be shared between Engine and Calc 
        EngineLib
#        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libEngineLib.so
)

INSTALL(TARGETS calc
        RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

#EOF
