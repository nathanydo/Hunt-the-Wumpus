CC=g++ -std=c++11 -g
exe=asm4

# Complete the makefile
# Your code here: 

$(exe): game.o room.o event.o bats.o stalactites.o gold.o wumpus.o armour.o main.cpp
	$(CC) game.o room.o event.o bats.o stalactites.o gold.o wumpus.o armour.o main.cpp -o $(exe)

game.o: game.cpp 
	$(CC) -c game.h game.cpp 

room.o: room.cpp
	$(CC) -c room.h room.cpp 

event.o: event.cpp
	$(CC) -c event.h event.cpp 

bats.o: ./game_modules/bats.cpp
	$(CC) -c ./game_modules/bats.h ./game_modules/bats.cpp 

stalactites.o: ./game_modules/stalactites.cpp
	$(CC) -c ./game_modules/stalactites.h ./game_modules/stalactites.cpp 

gold.o: ./game_modules/gold.cpp
	$(CC) -c ./game_modules/gold.h ./game_modules/gold.cpp 

wumpus.o: ./game_modules/wumpus.cpp
	$(CC) -c ./game_modules/wumpus.h ./game_modules/wumpus.cpp

armour.o: ./game_modules/armour.cpp
	$(CC) -c ./game_modules/armour.h ./game_modules/armour.cpp

clean:
	rm -f *.o $(exe)

