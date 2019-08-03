CC=g++

EXE=zoo

$(EXE):zoo_driver.o zoo.o animal.o tiger.o polar_bear.o penguin.o utility.o 
	 $(CC) zoo_driver.o zoo.o animal.o tiger.o polar_bear.o penguin.o utility.o -o $(EXE)

zoo_driver.o: zoo_driver.cpp
	$(CC) -c zoo_driver.cpp

zoo.o: zoo.cpp
	$(CC) -c zoo.cpp

animal.o: animal.cpp
	$(CC) -c animal.cpp

tiger.o: tiger.cpp
	$(CC) -c tiger.cpp

polar_bear.o: polar_bear.cpp
	$(CC) -c polar_bear.cpp

penguin.o: penguin.cpp
	$(CC) -c penguin.cpp

utility.o: utility.cpp
	$(CC) -c utility.cpp

clean: 
	rm -f *.out *.o $(EXE)
