project=problem3
objects=$(project).o
cc=gcc
.PHONY: clean

exec: $(project)
	./$< test.txt

all: $(objects)

$(project): $(objects)
	$(cc) -o $(project) $(objects)

$(objects): %.o: %.c
	$(cc) -c $(cflags) $< -o $@

clean:
	rm -f $(project) $(objects)
