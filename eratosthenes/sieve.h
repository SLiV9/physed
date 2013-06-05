#define LISTSIZE 100
#define NTHREADS 8

void init_sieve();
void free_sieve();

void start();
unsigned long get_prime();
void advance(unsigned long p);
void end();
