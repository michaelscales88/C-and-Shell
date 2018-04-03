exe=problem6
.PHONY: clean

exc: $(exe)
	./$< ps -l

test: exc clean

$(exe): $(exe).o
	gcc -o $@ $<

$(exe).o: $(exe).c
	gcc -Wall -g -c $(exe).c

clean:
	rm *.o $(exe)
