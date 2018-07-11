// Calc.cpp
// Author: Salik Siddiqui, July 2018

#include <iostream>
#include <string.h>

#include "Calc.h"
#include "EngineFactory.h"
#include "Engine.h"

int main( const int argc, const char ** argv )
{

    std::cout << "number of arguments: " << argc << std::endl;
    if( argc < 3 )
    {
        std::cout << "Not enough arguments." << std::endl;
        std::cout << "Example use cases:" << std::endl;
        std::cout << "\t./calc multi <file_list>" << std::endl;
        std::cout << "\t./calc div <file_list>" << std::endl;
        std::cout << "\t./calc div <number_list>" << std::endl;
        return -1;
    }

    std::cout << "Engine selected: " << argv[1]  << std::endl;
    
    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( argv[1], "calc engine", argc, argv, ARG_LIST );

    int readData_result = myEngine->ReadData();

    if( readData_result == 0 )
    {
        return myEngine->Calculate();
    }

    std::cout << "Error reading data. Not running calculation." << std::endl;
    return -1;

}


