CXX=g++
CXXFLAGS=-std=c++11 -Wall -g 

MKDIR_P = mkdir -p

all:
	${MKDIR_P} build/
	$(MAKE) -C Engine
	$(MAKE) -C Calculator


clean:
	$(MAKE) -C Engine clean
	$(MAKE) -C Calculator clean
	$(RM) -r build

