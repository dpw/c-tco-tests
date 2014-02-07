#include "common.h"

#define TCO_TEST(title, name, params1, args1, params2, args2)         \
void second_ ## name params2;                                         \
                                                                      \
void first_ ## name params1                                           \
{                                                                     \
	first_return_address = __builtin_return_address(0);           \
	second_ ## name args2;                                        \
}

#define TCO_RET_TEST(title, name, ret1, type1, type2, val)            \
type2 second_ ## name (void);                                         \
                                                                      \
type1 first_ ## name (void)                                           \
{                                                                     \
	first_return_address = __builtin_return_address(0);           \
	ret1 second_ ## name ();                                      \
}

#include "tests.h"
