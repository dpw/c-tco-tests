#include <stdio.h>

void *first_return_address;
void *second_return_address;

void accessible_local(void);
void nested_scope(void);
void with_inline_func(void);

static void check(void)
{
	printf(first_return_address == second_return_address
	       ? "TCO\n"
	       : "no TCO\n");
}

int main(void)
{
	printf("%-60s", "Tail call with exposed local var:");
	accessible_local();
	check();

	printf("%-60s", "Tail call with exposed local var in nested scope:");
	nested_scope();
	check();

	printf("%-60s", "Tail call with exposed local var in inline function:");
	with_inline_func();
	check();

	return 0;
}
