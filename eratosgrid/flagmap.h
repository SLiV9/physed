/* Flags and return values. */
#define BUSY -1
#define CLEAN 0
#define DIRTY 1
#define PRIME 2
#define WRONG 3

char get_flag(unsigned int d);
char set_flag(unsigned int d, char f);
