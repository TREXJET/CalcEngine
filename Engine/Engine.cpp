#include <iostream>
#include "Engine.h"
#include <sstream>
#include <fstream>

Engine::Engine( 
        std::string engine_name, 
        int numInputs, 
        char ** inputList, 
        AvailableInput inputTypes )
{
    m_name = engine_name;
    m_numInputs = numInputs;
    m_inputList = inputList;
    m_inputTypes = inputTypes;
}

Engine::Engine()
{
}

Engine::~Engine()
{
    std::cout << "Tearing down engine." << std::endl;
}

std::string Engine::get_name()
{
    return m_name;
}

int Engine::get_numInputs()
{
    return m_numInputs;
}


int Engine::ReadData()
{
    if( m_inputTypes == ARG_LIST )
    {
        return ReadArgsIntoVector();
    }
    else if( m_inputTypes == FILE_LIST )
    {
        return ReadFilesIntoVector();
    }
}

// It is unclear from the spec whether these will be comma separated, line
// separated, space separated, or delimited in some other way?
// Assuming comma separated values since that is a common format. 
//
//
// It would also be faster to open the file and multiply while reading the file
// instead of loading the entire file into the vector first, and then multiplying
// again. For the sake of time I'm going to implement the dumb method first.
int Engine::ReadFilesIntoVector()
{
    std::cout << "Reading file data into vector." << std::endl;

    // TODO append .txt to any files if they don't have it
    //      check whether an input has .txt appended to it already
    //      if not, append it
    
    
   
    // loop around files, loading all numbers into vector one by one
    for( int file_idx = 2; file_idx < m_numInputs; file_idx++ )
    {
        // open file
        std::cout << m_inputList[file_idx] << std::endl;
        std::string fileName = m_inputList[file_idx];
        std::ifstream currfile( fileName );
        std::string value;

        while( currfile.good() )
        {
            // read all integers, space and line separated into m_allInts
            long long int num;

            // I don't think CSV files support line breaks or anything other
            // than ',' as delimiters? 
            getline( currfile, value, ',' );
            std::istringstream inputStream( value ); 
            inputStream >> num;
            if( inputStream.fail() )
            {
                std::cout << "Data is invalid. Contains non-integer values. " << std::endl;
                return -1;
            }
            else
            {
                std::cout << "input data: " << num << std::endl;
            }

            m_allInts.push_back( num );
        }
    }
    return 0;
}

int Engine::ReadArgsIntoVector()
{
    // argNum = 2 because the first two arguments are not 
    // engine inputs
    for( int argNum = 2; argNum < m_numInputs; argNum++)
    {

        std::istringstream ss( m_inputList[argNum] );
        long long int number;
        if( ss >> number )
        {
            m_allInts.push_back( number );
            std::cout << "pushed back: " << number << std::endl;
        }
        else
        {
            std::cerr << "Invalid number: " << m_inputList[argNum] << std::endl;
        }
    }
    std::cout << "Read args into vector: " << std::endl; 
    for( auto & num : m_allInts )
    {
        std::cout << num << std::endl;
    }
    std::cout << std::endl;
}

