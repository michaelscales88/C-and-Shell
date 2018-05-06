project=problem4
objects=$(project).o
cc=gcc
cflags=-Wall -Werror -g
.PHONY: clean test

exec: $(project)
	./$< test/

test: setup exec clean

setup:
	mkdir test
	echo "stuff" >> test/test1.out test/test2.out
	mkdir test/test-deep
	echo "stuff" >> test/test-deep/deep.out

all: $(objects)

$(project): $(objects)
	$(cc) -o $(project) $(objects)

$(objects): %.o: %.c
	$(cc) -c $(cflags) $< -o $@

clean:
	rm -f $(project) $(objects)
