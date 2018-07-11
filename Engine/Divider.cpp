// Divider.cpp
// Author: Salik Siddiqui, July 2018

#include "Divider.h"

#include <iostream>
#include <string>
#include <functional>
#include <limits>

Divider::Ptr Divider::Create(
        std::string engine_name, 
        int numInputs, 
        const char ** inputList, 
        AvailableInput inputTypes )
{
    std::shared_ptr<Divider> pDivider = std::shared_ptr<Divider>( new Divider(
                engine_name, 
                numInputs,
                inputList,
                inputTypes ) );

    return pDivider;
}

Divider::Divider( 
        std::string engine_name, 
        int numInputs, 
        const char ** inputList, 
        AvailableInput inputTypes )
{
    m_name = engine_name;
    m_numInputs = numInputs;
    m_inputList = inputList;
    m_inputTypes = inputTypes;
    m_currTotal = 0;
}

// This calculate function performs sequential division on each number it received
// as input. 
//      
// Will return max size of long long int if a divide by 0 is attempted as the best
// way to represent INF. 
// Otherwise, prints and returns the result of dividing each number through the
// input data.
long long int Divider::Calculate()
{
    std::cout << "Divider starting calculation." << std::endl;

    if( m_allInts.size() < 1 )
    {
        std::cout << "No data, nothing to calculate." << std::endl;
        return 0;
    }
    m_currTotal = m_allInts[0];

    for( long long unsigned int index = 0; index < m_allInts.size()-1; index++ )
    {
        // Check to make sure a divide by 0 is not about to happen
        // Report result and exit if divide by 0 is about to happen
        if( m_allInts[index+1] == 0 )
        {
            std::cout << "Divide by 0 attempted. Exiting calculation." << std::endl;
            // If x/0 = infinity. 
            std::cout << "Divider Result: INF" << std::endl;
            m_currTotal = std::numeric_limits<long long int>::max();
            return m_currTotal;
        }

        m_currTotal = m_currTotal/m_allInts[index+1];
        std::cout << m_currTotal << std::endl;
    }
    std::cout << "Divider result: " << m_currTotal << std::endl;
    return m_currTotal;
}

