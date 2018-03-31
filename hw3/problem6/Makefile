TARGETS=problem6 foo.txt

exec: clear $(TARGETS)
	./$(TARGETS) r

testrplus: clear $(TARGETS)
	./$(TARGETS) r+

testw: clear $(TARGETS)
	./$(TARGETS) w

testwplus: clear $(TARGETS)
	./$(TARGETS) w+

testa: clear $(TARGETS)
	./$(TARGETS) a

testaplus: clear $(TARGETS)
	./$(TARGETS) a+

problem6: problem6.o
	gcc -Wall -o problem6 $<

problem6.o: problem6.c
	gcc -g -c $<

.PHONY: clean clear print
clean:
	rm *.o problem6

clear:
	echo "abc" > foo.txt
