#ifndef ENGINE_FACTORY_H
#define ENGINE_FACTORY_H

#include "Engine.h"
#include "Multiplier.h"
#include "Divider.h"

class EngineFactory
{
    public:
        std::shared_ptr<Engine> Create( 
                std::string engine_type,
                std::string engine_name, 
                int numInputs, 
                const char ** inputList, 
                AvailableInput inputTypes );
};

#endif /*ENGINE_FACTORY_H*/
