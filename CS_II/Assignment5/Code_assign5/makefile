CC=gcc

exe=run

$(exe): test_list.c list.c
	$(CC) test_list.c list.c -o $(exe)

clean:
	rm -f *.o *.out $(exe)
