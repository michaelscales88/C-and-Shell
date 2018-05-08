project=problem2
objects=$(project).o
cc=gcc
.PHONY: clean test

exec: $(project)
	./$< $<.c

test: file link dir

file: $(project)
	./$< afile.txt

link: $(project)
	./$< afilelink.link

dir: $(project)
	./$< adir

all: $(objects)

$(project): $(objects)
	$(cc) -o $(project) $(objects)

$(objects): %.o: %.c
	$(cc) -c $(cflags) $< -o $@

clean:
	rm -f $(project) $(objects)
