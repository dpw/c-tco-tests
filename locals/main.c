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
	printf("%-60s", "accessible_local:");
	accessible_local();
	check();

	printf("%-60s", "nested_scope:");
	nested_scope();
	check();

	printf("%-60s", "with_inline_func:");
	with_inline_func();
	check();

	return 0;
}
