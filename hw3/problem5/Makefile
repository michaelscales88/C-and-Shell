PROJ=foo
OBJS=$(PROJ).o
FILES=$(PROJ).c
.PHONY: clean testa testb testc testd teste

exec: $(PROJ) testa testb testc testd teste
	@echo "===== Completed Tests ====="

testa: $(PROJ)
	@echo "===== Start Test A ======"
	./$<
	@echo "===== End Test A ======"

testb: $(PROJ)
	@echo "===== Start Test B ======"
	./$< argument -b
	@echo "===== End Test B ======"

testc: $(PROJ)
	@echo "===== Start Test C ======"
	./$< argument --c
	@echo "===== End Test C ======"

testd: $(PROJ)
	@echo "===== Start Test D ======"
	./$< argument -x
	@echo "===== End Test D ======"

teste: $(PROJ)
	@echo "===== Start Test E ======"
	./$< argument -a -b
	@echo "===== End Test E ======"

$(PROJ): $(OBJS)
	gcc -o $(PROJ) $^

$(OBJS): $(FILES)
	gcc -g -c $^ -O3 -Wall

clean:
	rm -f $(OBJS) $(PROJ)
