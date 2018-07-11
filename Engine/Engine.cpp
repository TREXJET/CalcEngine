#include <iostream>
#include "Engine.h"
#include <sstream>
#include <fstream>

Engine::Engine( 
        std::string engine_name, 
        int numInputs, 
        const char ** inputList, 
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

// Getter to check the engine name
std::string Engine::get_name()
{
    return m_name;
}

// Reads data depending on the engine created by the user
// Calls the appropriate function read either command line arguments
// or files into a vector of integers for the engine to run
// its calculations on later.
//
// Will report failure -1 if:
//      No data was read in from the called functions
int Engine::ReadData()
{
    int read_result;
    if( m_inputTypes == ARG_LIST )
    {
        read_result = ReadArgsIntoVector();
    }
    else if( m_inputTypes == FILE_LIST )
    {
        read_result = ReadFilesIntoVector();
    }

    if( m_allInts.size() < 1 )
    {
        std::cout << "No data was read!" << std::endl;
        return -1;
    }
    return read_result;

}

// Reads file(s) into vector of ints.
//
// Will report failure -1 if:
//      Could not append .txt to the file name
//      File contained non-integer, non CSV data.
//
// It is unclear from the spec whether these will be comma separated, line
// separated, space separated, or delimited in some other way?
// Assuming comma separated values since that is a common format. 
//
// It would also be faster to open the file and multiply while reading the file
// instead of loading the entire file into the vector first, and then multiplying
// again. For the sake of simplicity I'm going to implement the dumb method first.'
int Engine::ReadFilesIntoVector()
{
    std::cout << "Reading file data into vector." << std::endl;

    const std::string txt = ".txt";
   
    // loop around files, loading all numbers into vector one by one
    for( int file_idx = 2; file_idx < m_numInputs; file_idx++ )
    {
        //      check whether an input has .txt appended to it already
        //      if not, append it
        std::string fileName = m_inputList[file_idx];
        std::cout << "Reading file: " << fileName << std::endl;
        
        // if file name smaller than ".txt" it can't contain the .txt substring.
        // append it.
        if( fileName.size() < txt.size() )
        {
            std::cout << "File does not have a .txt string at the end! Appending one." << std::endl;
            fileName = fileName + txt;
            std::cout << "New file name: " << fileName << std::endl;
        }
        // check the end of the file name for the .txt suffix. Append .txt if it doesn't have one'
        else if( 0 != fileName.compare( fileName.size() - txt.size(), txt.size(), txt ) )
        {
            // append .txt to any files if they don't have it
            std::cout << "File does not have a .txt string at the end! Appending one." << std::endl;
            fileName = fileName + txt;
            std::cout << "New file name: " << fileName << std::endl;
        }

        // open file
        std::cout << fileName << std::endl;
        std::ifstream currfile( fileName );
        std::string value;

        while( currfile.good() )
        {
            // read all integers, space and line separated into m_allInts
            long long int num;

            // I don't think CSV files support line breaks or anything other
            // than ',' or EOF as delimiters
            getline( currfile, value, ',' );
            std::istringstream inputStream( value ); 
            inputStream >> num;
            if( inputStream.fail() )
            {
                std::cout << "Data is invalid. Contains non-integer values. " << std::endl;
                return -1;
            }

            // Dump all numbers from the file into the m_allInts vector
            m_allInts.push_back( num );
        }
    }
    return 0;
}

// Read arguments from the command line into the m_allInts vector.
// 
// Reports failure -1 if:
//      any arguments are non-integer values
int Engine::ReadArgsIntoVector()
{
    // argNum = 2 because the first two arguments are not 
    // engine inputs
    for( int argNum = 2; argNum < m_numInputs; argNum++)
    {
        // read input list into istringstream
        std::istringstream ss( m_inputList[argNum] );
        long long int number;
        if( ss >> number )
        {
            // push each arg into m_allInts vector
            m_allInts.push_back( number );
        }
        else
        {
            // report error if bad data
            std::cerr << "Invalid number: " << m_inputList[argNum] << std::endl;
            return -1;
        }
    }
    return 0;
}

