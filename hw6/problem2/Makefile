project=problem2
objects=$(project).o
cc=gcc
.PHONY: clean test

exec: $(project)
	./$< $<.c

test: exec clean

all: $(objects)

$(project): $(objects)
	$(cc) -o $(project) $(objects)

$(objects): %.o: %.c
	$(cc) -c $(cflags) $< -o $@

clean:
	rm -f $(project) $(objects)
