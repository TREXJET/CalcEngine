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
        char ** inputList, 
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
        char ** inputList, 
        AvailableInput inputTypes )
{
    m_name = engine_name;
    m_numInputs = numInputs;
    m_inputList = inputList;
    // input argument types for multpilier are restricted to FILE_LIST, per the spec
    // TODO make sure the factory reminds user of this when they create multi
    m_inputTypes = inputTypes;
    m_currTotal = 0;
}

long long int Divider::Calculate()
{
    std::cout << "Divider starting calculation." << std::endl;

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
            m_currTotal = std::numeric_limits<float>::max();
            return m_currTotal;
        }

        m_currTotal = m_currTotal/m_allInts[index+1];
        std::cout << m_currTotal << std::endl;
    }
    std::cout << "Divider result: " << m_currTotal << std::endl;
    return m_currTotal;
}

