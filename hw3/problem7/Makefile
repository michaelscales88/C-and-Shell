exec: problem7
	./problem7

problem7: problem7.o
	gcc -Wall -o problem7 problem7.o

problem7.o: problem7.c
	gcc -g -c problem7.c -lm

.PHONY: clean
clean:
	rm problem7 *.o
