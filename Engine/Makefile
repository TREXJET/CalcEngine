# Makefile to build the Engine library

LIB_NAME = Engine
SRC_FILES = Engine.cpp Engine.h Multiplier.cpp Multiplier.h Divider.cpp Divider.h EngineFactory.cpp EngineFactory.h

.PHONY: lib$(LIB_NAME).so clean

lib$(LIB_NAME).so: $(SRC_FILES)
	 g++-8 $^ -g3 -fPIC -shared -Wl,-soname,./lib$(LIB_NAME).so -o $@
	 ln -sf ../Engine/lib$(LIB_NAME).so ../build/lib$(LIB_NAME).so 

clean:
	$(RM) lib$(LIB_NAME).so
	$(RM) ../build/lib$(LIB_NAME).so
