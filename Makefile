main: main.o Room.o Map.o
	g++ -std=c++11 -lSDL2 -lSDL2_image -lSDL2_ttf main.o Room.o Map.o -o main

main.o: main.cpp Room.h Map.h
	g++ -std=c++11 -c -lSDL2 -lSDL2_image -lSDL2_ttf main.cpp

Room.o: Room.cpp Room.h
	g++ -std=c++11 -c Room.cpp

Map.o:
	g++ -std=c++11 -c Map.cpp
