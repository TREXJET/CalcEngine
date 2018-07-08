// Multiplier.h
// Authoer: Salik Siddiqui, July 2018

#ifndef MULTI_H
#define MULTI_H

#include "Engine.h"

class Multiplier : public Engine, public std::enable_shared_from_this<Multiplier>
{
    public:
        typedef std::shared_ptr<Multiplier> Ptr;
        static Multiplier::Ptr Create(
                std::string engine_name, 
                int numInputs, 
                char ** inputList, 
                AvailableInput inputTypes );

        long long int Calculate( );

    private:
        Multiplier( 
                std::string engine_name, 
                int numInputs, 
                char ** inputList, 
                AvailableInput inputTypes );
        long long int m_currTotal;

};



#endif /* MULTI_H */
