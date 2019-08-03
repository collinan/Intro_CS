#Author-Andrew Collins
#Date: 4/10/2016
CC=g++
exe_file=state_info

$(exe_file):run_facts.o state_facts.o
	$(CC) run_facts.o state_facts.o -o $(exe_file)
run_facts.o:run_facts.cpp
	$(CC) -c run_facts.cpp
state_facts.o:state_facts.cpp
	$(CC) -c state_facts.cpp

clean:
	rm -f *.out *.o $(exe_file)
	
