#include "common.h"

#define TCO_TEST(title, name, params1, args1, params2, args2)         \
void second_ ## name params2                                          \
{                                                                     \
	second_return_address = __builtin_return_address(0);          \
}

#define TCO_RET_TEST(title, name, ret1, type1, type2, val)            \
type2 second_ ## name (void)                                          \
{                                                                     \
	second_return_address = __builtin_return_address(0);          \
	return val;                                                   \
}

#include "tests.h"
