#CPPFLAGS= -ggdb -O0 -fno-inline

all: Four_Right_Turns

Four_Right_Turns: main.o Room.o Map.o
	g++ -std=c++11 -lSDL2 -lSDL2_image -lSDL2_ttf main.o Room.o Map.o -o Four_Right_Turns

main.o: main.cpp Room.h Map.h
	g++ $(CPPFLAGS) -std=c++11 -c -lSDL2 -lSDL2_image -lSDL2_ttf main.cpp

Room.o: Room.cpp Room.h
	g++ $(CPPFLAGS) -std=c++11 -c Room.cpp

Map.o: Map.cpp Room.h
	g++ $(CPPFLAGS) -std=c++11 -c Map.cpp

clean:
	rm -f Four_Right_Turns main.o Room.o Map.o
