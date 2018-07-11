# Calculation Engine

## Usage:
    ./calc <engine_name> <file_list>
    ./calc <engine_name> <list of integers>

## Building the calculation engine and example calc program
    * From the top level: 'make'
    * 'cd build''
    * You will see two new files here: 'calc' and 'libEngine.so'
    * You can run the example calc program here. There are already some example input files in the build directory.


## Building and running unit tests
    * From the top level: 'make test'
    * 'cd build'
    * './TestEngine'

Files will contain one more more lines of integers. 
All files must be placed in the current working directory.

## Engine types:
    * multi - multiplies all integers together, only works with file list as
         input data

    * div - divides all the integers, one after another. Works with both file 
        list inputs and integer list inputs as input data

All engine output goes to stdout and is also returned by the engine API.

## Input data types:
    * Input argument types need to be decided at compile time. Contained in an enum "AvailableInput". Choices are:
        * ARG_LIST: List of integers on the command line. *Not supported by multiplier engines.*
        * FILE_LIST: List of CSV files. File type must be .txt, engine will auto-append .txt to inputs which don't have it.
            * Any non comma delimited or EOF delimited integers will be ignored
            * Any non integer values will cause the Engine data reader to fail


## Common Engine API:
    Users' command line arguments are passed into the factory, along with the Input Argument type
    The engine will return a pointer of type Engine::Ptr, which is simply a shared_ptr<Engine>.

    The user can now call *ReadData()* on the Engine object, which will parse all of the input args
    based on the AvailableInput type and put all of these into a vector.

    Error free parse will return 0.

    Any failures in parsing, or 0 data, will result in a -1 return.

## Multiplier API:
    The multiplier has one public API: Calculate(). Calculate multiplies all the numbers parsed by
    ReadData(), and returns a value of type long long int and also prints it to stdout.

    The multiplier cannot read from command line arguments. Only file inputs are supported.

## Divider API:
    The divider also has one public API: Calculate(). Calculate multiplies all the numbers parsed by
    ReadData(), and returns a value of type long long int and also prints it to stdout.

    If the divider encounters a 0, it will report this and return a max long long int as a representation
    of infinity. 

