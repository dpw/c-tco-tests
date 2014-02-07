extern void *second_return_address;

void target(void)
{
	second_return_address = __builtin_return_address(0);
}
