#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sched.h>

#include "buffer.h"
#include "sieve.h"

/* Intuitive namer. Do not change. */
#define EMPTY 0

/* How many primes have been calculated. 0 < listlength <= LISTSIZE. */
static unsigned int listlength;

/* The transfer slots are used by the segments to implement 'try'-spinning. 
 * By design, transfer[X] will be a number that was taken from buff[X - 1] and 
 * is about to be stored in buff[X], for X > 0; transfer[0] is an odd number. */
static unsigned long transfer[LISTSIZE];

/* The buffers used for storing numbers. By design, buff[X] will only contain 
 * numbers that are NOT divisible by prime[X]. */
static buffer* buff[LISTSIZE];

/* Pthreads. */
static pthread_t PT[NTHREADS];
static int PTID[NTHREADS];
static pthread_attr_t ptattr;

/* Sieve states. Increases by default. Do not change. */
#define ST_OFF 0
#define ST_READY 1
#define ST_RUNNING 2
#define ST_DONE 3
#define ST_FREE 4
static char State = ST_OFF;

/* The main method for segment threads, i.e. the NTHREADS threads created by 
 * the main thread. */
void* segment(void* arg)
{
  int id = *((int*) arg);
  
  printf("[S%d]\t Ready.\n", id);
  
  while (State < ST_RUNNING)
  {
    sched_yield();
  }
  
  while (State == ST_RUNNING)
  {
    if (id == NTHREADS)
    {
      if (add(buff[0], transfer[0]))
      {
        transfer[0] += 2;
      }
    }
    
    unsigned long x;
    
    for (int pos = id; pos < listlength; pos += NTHREADS)
    {
      if ((x = transfer[pos]))
      {
        if (add(buff[pos], x))
        {
          transfer[pos] = EMPTY;
        }
      }
      
      if (transfer[pos] == EMPTY)
      {
        if ((x = get(buff[pos - 1])))
        {
          if (x % prime[pos] != 0)
          {
            transfer[pos] = x;
          }
        }
      }
    }
  }
  
  printf("[S%d]\t Done.\n", id);
  
  return NULL;
}

/* If possible, returns the last created prime. If the last primebuffer is 
 * empty, 0 is returned. (Similar to buffer's get() function.) */
unsigned long get_prime()
{
  if (listlength > LISTSIZE)
  {
    printf("{ error } All %lu primes calculated.\n", (unsigned long) LISTSIZE);
    return NOMORE;
  }
  
  unsigned long p = get(buff[listlength - 1]);
  prime[listlength] = p;
  return p;
}

/* Advances the sieving. */
void advance()
{
  if (!prime[listlength])
  {
    printf("{ warning } Prime not yet calculated.\n");
    return;
  }
  
  if (listlength >= LISTSIZE)
  {
    printf("{ warning } Cannot advance; already full.\n");
    return;
  }
  
  buff[listlength] = init_buffer();
  listlength++;
}

/* Initialises the first buffer and creates the threads. */
void init_sieve()
{
  if (State != ST_OFF)
  {
    printf("{ warning } Sieve already initialised.\n");
    return;
  }
  
  prime[0] = 2;
  transfer[0] = 3;
  buff[0] = init_buffer();
  for (int i = 1; i < LISTSIZE; i++)
  {
    prime[i] = 0;
    transfer[i] = 0;
    buff[i] = NULL;
  }
  listlength = 1;
  
  pthread_attr_init(&ptattr);
  pthread_attr_setscope(&ptattr, PTHREAD_SCOPE_SYSTEM);
  
  for (int i = 0; i < NTHREADS; i++)
  {
    PTID[i] = i + 1;
    if (pthread_create(&PT[i], &ptattr, &segment, &PTID[i]))
    {
      printf("{ fatal error } Could not create pthread %d.\n", i);
      exit(-1);
    }
  }
  
  State = ST_READY;
}

/* Frees all initialised buffers and destroys the threads. */
void free_sieve()
{
  if (State != ST_DONE)
  {
    printf("{ warning } Sieve has not finished or already freed.\n");
    return;
  }
  
  for (int i = 0; i < NTHREADS; i++)
  {
    if (pthread_join(PT[i], NULL))
    {
      printf("{ error } Could not join pthread %d.\n", i);
    }
  }
  
  for (int i = 0; i < LISTSIZE; i++)
  {
    if (buff[i])
    {
      free_buffer(buff[i]);
    }
  }
  
  State = ST_FREE;
}

/* Starts the sieving. */
void start()
{
  if (State == ST_READY)
  {
    State = ST_RUNNING;
  }
  else
  {
    printf("{ warning } Sieve not yet ready or already started.\n");
  }
}

/* Ends the sieving. */
void end()
{
  if (State == ST_RUNNING)
  {
    State = ST_DONE;
  }
  else
  {
    printf("{ warning } Sieve not running.\n");
  }
}
