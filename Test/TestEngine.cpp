// TestEngine.cpp
// Tests for calculation Engine library
// Author: Salik Siddiqui, July 2018

#include <iostream>
#include <string.h>
#include <limits>
#include <cassert>

#include "TestEngine.h"
#include "EngineFactory.h"
#include "Engine.h"

int main( const int argc, const char ** argv )
{
    TestDividerArgList();
    TestDividerFileList();
    TestMultiplierFileList();
    TestBadData();
    TestBadDataArgs();
    TestDivideBy0();
    TestMultiplyBy0();
    TestTinyFileName();
    TestMultiplierReadArgsList();
}

// Test normal operation of divider with command line input
void TestDividerArgList()
{
    std::cout << "=========================" << std::endl;
    std::cout << "TestDividerArgList" << std::endl;
    std::cout << "=========================" << std::endl;
    const int numInputs = 4;
    const char* inputList[] = { "./calc", "div", "10", "2" };

    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( "div", "calc engine", numInputs, inputList, ARG_LIST );

    assert( myEngine->ReadData() == 0 );
    assert(myEngine->Calculate() == 5); 
}

// Test normal operation of divider with file input 
// Also implicitly tests appending of .txt to files that don't already have them
void TestDividerFileList()
{
    std::cout << "=========================" << std::endl;
    std::cout << "TestDividerFileList" << std::endl;
    std::cout << "=========================" << std::endl;
    const int numInputs = 4;
    const char* inputList[] = { "./calc", "div", "test_data", "test_data2.txt" };

    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( "div", "calc engine", numInputs, inputList, FILE_LIST );

    assert( myEngine->ReadData() == 0 );
    assert(myEngine->Calculate() == 2); 
}

// Test normal operation of multiplier with file input
void TestMultiplierFileList()
{
    std::cout << "=========================" << std::endl;
    std::cout << "TestMultiplierFileList" << std::endl;
    std::cout << "=========================" << std::endl;
    const int numInputs = 4;
    const char* inputList[] = { "./calc", "multi", "test_data", "test_data2" };

    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( "multi", "calc engine", numInputs, inputList, FILE_LIST );

    assert( myEngine->ReadData() == 0 );
    assert(myEngine->Calculate() == 200); 
}

// Test to ensure error from engine which recieves non integer, 
// non csv data (see test_bad_data.txt)
void TestBadData()
{
    std::cout << "=========================" << std::endl;
    std::cout << "TestBadData" << std::endl;
    std::cout << "=========================" << std::endl;
    const int numInputs = 3;
    const char* inputList[] = { "./calc", "multi", "test_bad_data" };

    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( "multi", "calc engine", numInputs, inputList, FILE_LIST );

    assert( myEngine->ReadData() == -1 );
}

// Test to ensure error from engine which recieves bad data on the command line
void TestBadDataArgs()
{
    std::cout << "=========================" << std::endl;
    std::cout << "TestBadDataArgs" << std::endl;
    std::cout << "=========================" << std::endl;
    const int numInputs = 3;
    const char* inputList[] = { "./calc", "multi", "bad", "data", "1.2" };

    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( "div", "calc engine", numInputs, inputList, ARG_LIST );

    assert( myEngine->ReadData() == -1 );
}
// Test to ensure correct behavior of divider engine when it is about to divide by 0
void TestDivideBy0()
{
    std::cout << "=========================" << std::endl;
    std::cout << "TestDivideBy0" << std::endl;
    std::cout << "=========================" << std::endl;
    const int numInputs = 5;
    const char* inputList[] = { "./calc", "div", "10", "5", "0" };

    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( "div", "calc engine", numInputs, inputList, ARG_LIST );

    assert( myEngine->ReadData() == 0 );
    assert(myEngine->Calculate() == std::numeric_limits<long long int>::max() ); 
}

// Test to ensure correct behavior of multiplier engine when it encounters a 0
void TestMultiplyBy0()
{
    std::cout << "=========================" << std::endl;
    std::cout << "TestMultiplyBy0" << std::endl;
    std::cout << "=========================" << std::endl;
    const int numInputs = 5;
    const char* inputList[] = { "./calc", "multi", "test_multiply_by_0" };

    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( "multi", "calc engine", numInputs, inputList, FILE_LIST );

    assert( myEngine->ReadData() == 0 );
    assert(myEngine->Calculate() == 0 ); 
}

// Test to ensure file arguments with names of length shorter than ".txt" don't
// cause a crash.
void TestTinyFileName()
{
    std::cout << "=========================" << std::endl;
    std::cout << "TestTinyFileName" << std::endl;
    std::cout << "=========================" << std::endl;
    const int numInputs = 4;
    const char* inputList[] = { "./calc", "multi", "t1", "t2" };

    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( "multi", "calc engine", numInputs, inputList, FILE_LIST );

    assert( myEngine->ReadData() == 0 );
    assert(myEngine->Calculate() == 600 ); 
}

// Test to make sure Multiplier engine reports and will not work with argument
// inputs from the command line. Per the spec it's only supposed to work with
// Files as its arguments
void TestMultiplierReadArgsList()
{
    std::cout << "=========================" << std::endl;
    std::cout << "TestMultiReadArgsList" << std::endl;
    std::cout << "=========================" << std::endl;
    const int numInputs = 5;
    const char* inputList[] = { "./calc", "multi", "1", "2", "3" };

    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( "multi", "calc engine", numInputs, inputList, ARG_LIST );

    assert( myEngine->ReadData() == -1 );
}

