/* If you need more primes, increase LISTSIZE.
 * For more threads, increase NTHREADS. */
#define LISTSIZE 100
#define NTHREADS 8

/* Intuitive namers; do not change. */
#define BUSY 0
#define NOMORE 1

/* The list of primes. */
unsigned long prime[LISTSIZE];

// USER GUIDE
/*
    init_sieve();
    start();

    while (YOUR_CONDITION(p, index))
    {
      while ((p = get_prime) == BUSY);
      if (index < LISTSIZE)
        advance();
    }

    end();
    free_sieve();
    
    p24 = prime[24 - 1];
    // prime[0] == 2
*/

void init_sieve();
void free_sieve();

void start();
void end();

unsigned long get_prime();
void advance();
