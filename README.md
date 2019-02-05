# Calculation Engine

## Usage:
    ./calc <engine_name> <file_list>
    ./calc <engine_name> <list of integers>

## Building the calculation engine and example calc program
    * From the top level: `cmake CMakeLists.txt`
    * From the top level: 'make'
    * 'cd build''
    * You will see three new files here: 'calc', 'libEngine.so', and `TestEngine`
    * You can run the example calc program here. There are already some example input files in 'build'


## Running unit tests
    * After doing a build following the steps above:
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

## Directory map
```
.
├── build
│   ├── input_data_2.txt
│   ├── input_data_3.txt
│   ├── input_data.txt
│   ├── t1.txt
│   ├── t2.txt
│   ├── test_bad_data.txt
│   ├── test_data2.txt
│   ├── test_data.txt
│   └── test_multiply_by_0.txt
├── Calculator
│   ├── Calc.cpp
│   ├── Calc.h
│   └── mk.old
├── CMakeLists.txt
├── Engine
│   ├── CMakeLists.txt
│   ├── Divider.cpp
│   ├── Divider.h
│   ├── Engine.cpp
│   ├── EngineFactory.cpp
│   ├── EngineFactory.h
│   ├── Engine.h
│   ├── lib.cmake
│   ├── mk.old
│   ├── Multiplier.cpp
│   └── Multiplier.h
├── exe.cmake
├── mk.old
├── Programming_exercise_cpp.doc.pdf
├── README.md
└── Test
    ├── CMakeLists.txt
    ├── exe.cmake
    ├── TestEngine.cpp
    └── TestEngine.h

4 directories, 32 files
```
