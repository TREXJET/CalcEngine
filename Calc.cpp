// Calc.cpp
// Author: Salik Siddiqui, July 2018

#include <iostream>
#include <string.h>

#include "Calc.h"
#include "EngineFactory.h"
#include "Engine.h"

long long int main( const int argc, const char ** argv )
{

    std::cout << "number of arguments: " << argc << std::endl;
    if( argc < 3 )
    {
        std::cout << "Not enough arguments." << std::endl;
        std::cout << "Example use cases:" << std::endl;
        std::cout << "\t./calc multi <file_list>" << std::endl;
        std::cout << "\t./calc div <file_list>" << std::endl;
        std::cout << "\t./calc div <number_list>" << std::endl;
        std::cout << "\t Note: engine type 'multi' cannot read number lists from the command line. File inputs only." << std::endl;
        return -1;
    }

    std::cout << "Engine selected: " << argv[1]  << std::endl;
    
    // Create factor and get an engine from it
    EngineFactory eFactory;
    Engine::Ptr myEngine = eFactory.Create( argv[1], "calc engine", argc, argv, ARG_LIST );

    // Have the engine read the input data
    int readData_result = myEngine->ReadData();

    // If the data was read okay, run calculations on the data and return the result.
    if( readData_result == 0 )
    {
        return myEngine->Calculate();
    }

    // report an error if there were any issues during calculation and return -1.
    std::cout << "Error reading data. Not running calculation." << std::endl;
    return -1;

}


