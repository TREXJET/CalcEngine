// EngineFactory.cpp
// Author: Salik Siddiqui, July 2018
#include <iostream>
#include "EngineFactory.h"

// The engine factory simply returns a pointer to the type of engine 
// based on the engine type selected on the command line.
std::shared_ptr<Engine> EngineFactory::Create(
        std::string engine_type,
        std::string engine_name, 
        int numInputs, 
        const char ** inputList, 
        AvailableInput inputTypes )       
{

    if( std::string(engine_type) == "multi" )
    {
        std::cout << "Creating multiplier engine." << std::endl;
        std::cout << "Note: multiplier engine only accepts files as its input type." << std::endl;
        return Multiplier::Create("multiplier_engine", numInputs, inputList, FILE_LIST ) ;
    }
    else if( std::string(engine_type) == "div" )
    {
        std::cout << "Creating divider engine." << std::endl;
        return Divider::Create("divider_engine", numInputs, inputList, inputTypes);

    }
    return nullptr;
}
