##Program filename:makefile
##Author: Andrew Collins
##Date;5/8/2016
##Description: make file for wumpus program
CC=g++

exe=start

$(exe):play_game.o game.o driver.o room.o wumpus.o bats.o pit.o gold.o
	$(CC) play_game.o game.o driver.o room.o wumpus.o bats.o pit.o gold.o -o $(exe)

play_game.o: play_game.cpp
	$(CC) -c play_game.cpp

game.o: game.cpp
	$(CC) -c game.cpp

driver.o: driver.cpp
	$(CC) -c driver.cpp

room.o:room.cpp
	$(CC) -c room.cpp

wumpus.o:wumpus.cpp
	$(CC) -c wumpus.cpp

bats.o:bats.cpp
	$(CC) -c bats.cpp

pit.o:pit.cpp
	$(CC) -c pit.cpp

gold.o:gold.cpp
	$(CC) -c gold.cpp

##event.o:event.cpp
#	$(CC) -c event.cpp





clean: 
	rm -f *.o *.out $(exe) 
