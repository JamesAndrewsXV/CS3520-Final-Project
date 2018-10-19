# project source and header files
SOURCES=src/main.cpp
HEADERS=

# test header files
TESTS=tests/exampletest.h

# C++ compile and linker flags
CPPFLAGS=-O0 `sdl2-config --cflags`
LDFLAGS=`sdl2-config --libs` -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lGL

# additional lists
MAIN_OBJECTS=$(SOURCES:.cpp=.o)


# rules
all: main

main: $(MAIN_OBJECTS)
	g++ -std=c++11 $(LDFLAGS) $^ -o $@


$(MAIN_OBJECTS): %.o: %.cpp $(HEADERS) Makefile
	g++ -std=c++11 $(CPPFLAGS) -c $< -o $@


clean:
	rm -f main $(MAIN_OBJECTS) *~
