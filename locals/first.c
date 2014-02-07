void target(void);

extern void *first_return_address;
int *global_var;

void accessible_local(void)
{
	int x = 42;
	first_return_address = __builtin_return_address(0);
	global_var = &x;
	target();
}

void nested_scope(void)
{
	first_return_address = __builtin_return_address(0);

	{
		int x = 42;
		global_var = &x;
	}

	target();
}

static __inline__ void inline_bit(void)
{
	int x = 42;
	global_var = &x;
}

void with_inline_func(void)
{
	first_return_address = __builtin_return_address(0);
	inline_bit();
	target();
}
