.PHONY: all run clean

MORE_CFLAGS=-Wall -Wextra -Wno-unused-parameter
CFLAGS=-O6

all: chaining/chaining locals/locals

chaining/chaining: $(addprefix chaining/,main.c first.c second.c tests.h common.h)
	$(CC) $(CFLAGS) $(MORE_CFLAGS) $(filter-out %.h,$^) -o $@

run:: all
	chaining/chaining

locals/locals: $(addprefix locals/,main.c first.c second.c)
	$(CC) $(CFLAGS) $(MORE_CFLAGS) $^ -o $@

clean::
	rm -f *~ chaining/*~ chaining/chaining locals/locals

