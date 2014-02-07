#ifdef __x86_64__
#define REG_PARAMS_FILLER int rpf1, int rpf2, int rpf3, int rpf4, int rpf5, int rpf6
#define REG_PARAMS_FILLER_ARGS 0, 0, 0, 0, 0, 0
#endif

#ifdef __arm__
#define REG_PARAMS_FILLER int rpf1, int rpf2, int rpf3, int rpf4
#define REG_PARAMS_FILLER_ARGS 0, 0, 0, 0
#endif

extern void *first_return_address;
extern void *second_return_address;
