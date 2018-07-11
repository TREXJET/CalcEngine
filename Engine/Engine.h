#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <memory>
#include <vector>

enum AvailableInput
{
    // list of numbers on the command line
    ARG_LIST   = 0,
    // list of files to be read in
    FILE_LIST  = 1,
};

class Engine
{
    public:
        typedef std::shared_ptr<Engine> Ptr;
        Engine( 
                std::string engine_name, 
                int numInputs, 
                const char ** inputList, 
                AvailableInput inputTypes );
        ~Engine();

        std::string get_name();
        int get_numInputs();

        // The default calculate type simply prints numInputs
        virtual long long int Calculate() = 0;
        int ReadData();

        
    protected:
        Engine();
        std::string m_name;
        int m_numInputs;
        const char **m_inputList;
        AvailableInput m_inputTypes;

        int ReadFilesIntoVector();
        int ReadArgsIntoVector();
        std::vector<long long int> m_allInts;
};

#endif /*ENGINE_H*/
