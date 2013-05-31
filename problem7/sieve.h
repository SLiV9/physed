#include "buffer.h"

#define NSIEVES 8

typedef struct sieve
{
  struct sieve *next;
  unsigned long buffer[BUFFERSIZE];
  unsigned long primes[NPRIMES];
}
