
SET( CALC_EXE 
        calc 
)

# don't know if we need this SET( CMAKE_EXE_LINKER_FLAGS "")

SET( CALC_SRCS 
    Calc.cpp
)

ADD_EXECUTABLE(
        ${CALC_EXE} 
        ${CALC_SRCS}
)


TARGET_LINK_LIBRARIES(
        ${CALC_EXE} 
        # TODO set this binary location in the top level cmake
        # so the output binary path can be shared between Engine and Calc 
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libEngineLib.so
)

message("cmake binary dir:" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
INSTALL(TARGETS calc
        RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
#EOF
