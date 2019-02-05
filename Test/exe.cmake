SET( TEST_EXE 
        TestEngine
)

SET( TEST_SRCS 
    TestEngine.cpp
)

ADD_EXECUTABLE(
        ${TEST_EXE} 
        ${TEST_SRCS}
)


TARGET_LINK_LIBRARIES(
        ${TEST_EXE} 
        EngineLib
)

INSTALL(TARGETS TestEngine 
        RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

#EOF
