#include <stdio.h>

#include "common.h"

void *first_return_address;
void *second_return_address;

#define TCO_TEST(title, name, params1, args1, params2, args2)         \
void first_ ## name params1;

#define TCO_RET_TEST(title, name, ret1, type1, type2, val)            \
type1 first_ ## name (void);

#include "tests.h"
#undef TCO_TEST
#undef TCO_RET_TEST

static void check(void)
{
	printf(first_return_address == second_return_address
	       ? "TCO\n"
	       : "no TCO\n");
}


int main(void)
{
#define TCO_TEST(title, name, params1, args1, params2, args2)         \
	printf("%-60s", title ":");				      \
	first_ ## name args1;                                         \
	check();

#define TCO_RET_TEST(title, name, ret1, type1, type2, val)            \
	printf("%-60s", title ":");                                   \
	first_ ## name ();                                            \
	check();

#include "tests.h"

	return 0;
}
