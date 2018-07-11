# Makefile for calc

CXX=g++
CXXFLAGS=-std=c++11 -Wall -g 

INC_PATH=-I.. -I ../Engine/ 
LINK_PATH=-L../Engine

all:
	$(CXX) $(CXXFLAGS) -o ../build/calc Calc.cpp Calc.h $(INC_PATH) $(LINK_PATH) -lEngine

clean:
	$(RM) calc
	$(RM) ../build/calc
