CXX=g++
CXXFLAGS=-std=c++11 -Wall -g 

INC_PATH=-I.. -I ../Engine/ 
LINK_PATH=-L../Engine

all:
	$(CXX) $(CXXFLAGS) -o ../build/TestEngine TestEngine.cpp TestEngine.h $(INC_PATH) $(LINK_PATH) -lEngine

clean:
	$(RM) TestEngine
	$(RM) ../build/TestEngine
