// TestEngine.cpp
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
    TestDivideBy0();
    TestMultiplyBy0();
    TestTinyFileName();
    TestMultiplierReadArgsList();
}

// Testing to make sure divider runs and returns the correct output
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

void TestDividerFileList()
{
    std::cout << "=========================" << std::endl;
    std::cout << "TestDividerFileList" << std::endl;
    std::cout << "=========================" << std::endl;
    const int numInputs = 4;
    const char* inputList[] = { "./calc", "div", "test_data", "test_data2" };

    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( "div", "calc engine", numInputs, inputList, FILE_LIST );

    assert( myEngine->ReadData() == 0 );
    assert(myEngine->Calculate() == 2); 
}

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

// Expected to fail, since the multiplier should only be able to read files per the spec.
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

