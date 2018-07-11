// Divider.h
// Authoer: Salik Siddiqui, July 2018

#ifndef DIV_H
#define DIV_H

#include "Engine.h"

class Divider : public Engine, public std::enable_shared_from_this<Divider>
{
    public:
        typedef std::shared_ptr<Divider> Ptr;
        static Divider::Ptr Create(
                std::string engine_name, 
                int numInputs, 
                const char ** inputList, 
                AvailableInput inputTypes );

        long long int Calculate( );
    private:
        Divider( 
                std::string engine_name, 
                int numInputs, 
                const char ** inputList, 
                AvailableInput inputTypes );
        long long int m_currTotal;

};



#endif /* DIV_H */
