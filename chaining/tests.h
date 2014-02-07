TCO_TEST("No arguments", zero,
	 (void), (),
	 (void), ())

TCO_TEST("One argument", one,
	 (int a), (0),
	 (int a), (0))

TCO_TEST("Additional int argument", zero_one,
	 (void), (),
	 (int a), (0))

TCO_TEST("Dropped int argument", one_zero,
	 (int a), (0),
	 (void), ())

#ifdef REG_PARAMS_FILLER
TCO_TEST("Additional int argument, with filler args", zero_one_filler,
	 (REG_PARAMS_FILLER), (REG_PARAMS_FILLER_ARGS),
	 (REG_PARAMS_FILLER, int a), (REG_PARAMS_FILLER_ARGS, 0))
#endif

TCO_TEST("Double argument replacing an int", int_double,
	 (int a), (0),
	 (double a), (0))

#ifdef REG_PARAMS_FILLER
TCO_TEST("Double argument replacing an int, with filler args",
	 int_double_filler,
	 (REG_PARAMS_FILLER, int a), (REG_PARAMS_FILLER_ARGS, 0),
	 (REG_PARAMS_FILLER, double a), (REG_PARAMS_FILLER_ARGS, 0))
#endif

TCO_RET_TEST("char return to int",
	     ret_int_char,
	     return, int, char, 0)

TCO_RET_TEST("int return to char",
	     ret_char_int,
	     return, char, int, 0)

TCO_RET_TEST("int return to void",
	     ret_void_int,
	     , void, int, 0)

TCO_RET_TEST("Pointer return to long",
	     ret_long_ptr,
	     return (long), long, void *, 0)
