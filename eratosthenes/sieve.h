#define LISTSIZE 100
#define NTHREADS 8

#define BUSY 0
#define NOMORE 1

unsigned long prime[LISTSIZE];

void init_sieve();
void free_sieve();

void start();
unsigned long get_prime();
void advance(unsigned long p);
void end();
