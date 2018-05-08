project=problem3
objects=$(project).o
cc=gcc
.PHONY: clean test normal ascending

exec: $(project)
	./$< .

normal: $(project)
	./$< test/

ascending: $(project)
	./$< test/ -a

test: exec clean

all: $(objects)

$(project): $(objects)
	$(cc) -o $(project) $(objects)

$(objects): %.o: %.c
	$(cc) -c $(cflags) $< -o $@

clean:
	rm -f $(project) $(objects)
