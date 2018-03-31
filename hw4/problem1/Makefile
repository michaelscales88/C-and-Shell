exc: problem1
	./$<

problem1: problem1.o
	gcc -o problem1 $<

problem1.o: problem1.c
	gcc -Wall -g -c problem1.c

clean:
	rm *.o problem1
