// Multiplier.cpp
// Author: Salik Siddiqui, July 2018

#include "Multiplier.h"
#include <iostream>
#include <string>
#include <limits>


Multiplier::Ptr Multiplier::Create(
        std::string engine_name, 
        int numInputs, 
        char ** inputList, 
        AvailableInput inputTypes )
{
    std::shared_ptr<Multiplier> pMultiplier = std::shared_ptr<Multiplier>( new Multiplier(
                engine_name, 
                numInputs,
                inputList,
                inputTypes ) );

    return pMultiplier;
}
Multiplier::Multiplier( 
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
    m_inputTypes = FILE_LIST;
    m_currTotal = 0;
}



long long int Multiplier::Calculate()
{
    std::cout << "Multiplier starting calculation." << std::endl;

    m_currTotal = m_allInts[0];

    for( long long unsigned int index = 0; index < m_allInts.size()-1; index++ )
    {
        // Multiply by 0 once, and the rest is 0's. Can return once this happens.
        if( m_currTotal == 0 )
        {
            std::cout << "Multiply by 0." << std::endl;
            std::cout << "Multiplier result: " << m_currTotal << std::endl;
            return m_currTotal;
        }

        m_currTotal = m_currTotal*m_allInts[index+1];
        std::cout << m_currTotal << std::endl;
    }
    std::cout << "Multiplier result: " << m_currTotal << std::endl;
    return m_currTotal;
}

