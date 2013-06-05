#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "buffer.h"
#include "sieve.h"

#define FIRSTPRIME 5
#define PRIMEOFFSET 3

#define ST_OFF 0
#define ST_RUNNING 1
#define ST_DONE 2

unsigned long prime_list[LISTSIZE];
unsigned long transfer_list[LISTSIZE];
buffer buffer_list[LISTSIZE];
unsigned int listlength;

static pthread_t PT[NTHREADS];
static pthread_attr_t ptattr;

char State = ST_OFF;

void init_sieve()
{
  listlength = 0;
}

void free_sieve()
{
}

void start()
{
  if (State == ST_OFF)
  {
    State = ST_RUNNING;
  }
  else
  {
    printf("{ error } Sieve already started.\n");
  }
}

void end()
{
  if (State == ST_RUNNING)
  {
    State = ST_DONE;
  }
  else
  {
    printf("{ error } Sieve not running.\n");
  }
}
