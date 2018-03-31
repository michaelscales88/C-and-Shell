exe=problem2
.PHONY: clean

exc: $(exe)
	./$<

test: exc clean

$(exe): $(exe).o
	gcc -o $@ $<

$(exe).o: $(exe).c
	gcc -Wall -g -c $(exe).c

clean:
	rm *.o $(exe)
