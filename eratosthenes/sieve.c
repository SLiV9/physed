#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sched.h>

#include "buffer.h"
#include "sieve.h"

#define ST_OFF 0
#define ST_READY 1
#define ST_RUNNING 2
#define ST_DONE 3
#define ST_FREE 4
#define EMPTY 0

unsigned long prime[LISTSIZE];
unsigned int listlength;

static unsigned long transfer[LISTSIZE];
static buffer* buff[LISTSIZE];

static pthread_t PT[NTHREADS];
static int PTID[NTHREADS];
static pthread_attr_t ptattr;

static char State = ST_OFF;

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
        if ((x = get(buff[pos])))
        {
          transfer[pos] = x;
        }
      }
    }
  }
  
  printf("[S%d]\t Done.\n", id);
  
  return NULL;
}

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
