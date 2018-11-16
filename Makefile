CXXTEST_HOME ?= cxxtest-4.4
CXXTEST_GEN = $(CXXTEST_HOME)/bin/cxxtestgen
CXXTEST_INCLUDE = $(CXXTEST_HOME)

CC = g++ -std=c++11 
CFLAGS= -c -ansi -Wall
#CPPFLAGS= -ggdb -O0 -fno-inline
LDFLAGS= -lSDL2 -lSDL2_image -lSDL2_ttf
SRC= main.cpp Room.cpp Loader.cpp Four_Right_Turns.cpp Map.cpp LTexture.cpp #add new files here!
OBJ= $(SRC:.cpp=.o)
EXECUTABLE= Four_Right_Turns

all: $(EXECUTABLE)

Four_Right_Turns: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -I$(CXXTEST_INCLUDE) -o Four_Right_Turns

Map.cxxtest.o: Map.cxxtest.hpp
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(CXXTEST_INCLUDE) Map.cxxtest.hpp

%.o: %.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(CXXTEST_INCLUDE) $<

Map.cxxtest.hpp:
	$(CXXTEST_GEN) --part --error-printer -o $@

main.cpp:
	$(CXXTEST_GEN) --root --error-printer -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJ)
