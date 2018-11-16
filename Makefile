#CPPFLAGS= -ggdb -O0 -fno-inline
CXXTEST_HOME ?= cxxtest-4.4
CXXTEST_GEN = $(CXXTEST_HOME)/bin/cxxtestgen
CXXTEST_INCLUDE = $(CXXTEST_HOME)

all: Four_Right_Turns

Four_Right_Turns: main.o Room.o Map.o Loader.o Four_Right_Turns.o LTexture.o
	g++ -std=c++11 -lSDL2 -lSDL2_image -lSDL2_ttf main.o Room.o Loader.o Four_Right_Turns.o Map.o LTexture.o -I$(CXXTEST_INCLUDE) -o Four_Right_Turns

main.o: main.cpp Four_Right_Turns.h
	g++ -std=c++11 -c -I$(CXXTEST_INCLUDE) main.cpp
	
Loader.o: Loader.cpp Loader.h LTexture.h
	g++ -std=c++11 -c -ansi -Wall -lSDL2 -lSDL2_image -lSDL2_ttf -I$(CXXTEST_INCLUDE) Loader.cpp
	
LTexture.o: LTexture.cpp LTexture.h
	g++ -std=c++11 -c -ansi -Wall -lSDL2 -lSDL2_image -lSDL2_ttf -I$(CXXTEST_INCLUDE) LTexture.cpp
	
Room.o: Room.cpp Room.h
	g++ -std=c++11 -c -ansi -Wall -I$(CXXTEST_INCLUDE) Room.cpp

Map.o: Map.cpp Room.h
	g++ -std=c++11 -c -ansi -Wall -I$(CXXTEST_INCLUDE) Map.cpp

Four_Right_Turns.o: Four_Right_Turns.h Four_Right_Turns.cpp
	g++ -std=c++11 -c -ansi -Wall -lSDL2 -lSDL2_image -lSDL2_ttf -I$(CXXTEST_INCLUDE) Four_Right_Turns.cpp

Map.cxxtest.o: Map.cxxtest.hpp
	g++ -std=c++11 -c -ansi -Wall -I$(CXXTEST_INCLUDE) Map.cxxtest.hpp

Map.cxxtest.hpp:
	$(CXXTEST_GEN) --part --error-printer -o Map.cxxtest.hpp

main.cpp:
	$(CXXTEST_GEN) --root --error-printer -o main.cpp

clean:
	rm -f Four_Right_Turns Four_Right_Turns.o main.o Room.o Map.o LTexture.o Loader.o
