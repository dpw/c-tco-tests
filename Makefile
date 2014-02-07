.PHONY: all run clean

all: chaining/chaining locals/locals

chaining/chaining: $(addprefix chaining/,main.c first.c second.c tests.h common.h)
	$(CC) $(CFLAGS) $(filter-out %.h,$^) -o $@

run:: all
	chaining/chaining

locals/locals: $(addprefix locals/,main.c first.c second.c)
	$(CC) $(CFLAGS) $^ -o $@

clean::
	rm -f *~ chaining/*~ chaining/chaining locals/locals

