project=problem3
objects=$(project).o
cc=gcc
.PHONY: clean test

exec: $(project)
	./$< . -a

test: exec clean

all: $(objects)

$(project): $(objects)
	$(cc) -o $(project) $(objects)

$(objects): %.o: %.c
	$(cc) -c $(cflags) $< -o $@

clean:
	rm -f $(project) $(objects)
