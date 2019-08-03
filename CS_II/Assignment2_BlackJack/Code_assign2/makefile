CC=g++
exe_file=blackjack

$(exe_file): hand.o deck.o player.o dealer.o  game.o play_game.o
	$(CC)  hand.o deck.o player.o dealer.o game.o play_game.o   -o $(exe_file)

hand.o: hand.cpp
	$(CC) -c hand.cpp

deck.o: deck.cpp
	$(CC) -c deck.cpp

player.o:player.cpp
	$(CC) -c player.cpp

dealer.o:dealer.cpp
	$(CC) -c dealer.cpp

play_game.o: play_game.cpp
	$(CC) -c play_game.cpp

game.o:game.cpp
	$(CC) -c game.cpp

clean:
	rm -f *.out *.o $(exe_file)
