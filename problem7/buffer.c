#include <stdlib.h>
#include <stdio.h>
#include <sched.h>
#include <pthread.h>

#include "buffer.h"

buffer* init_buffer(unsigned long p)
{
  buffer* B = malloc(sizeof(buffer));
  if (!B)
  {
    printf("{ fatal error } Could not allocate buffer with prime %lu.\n", p);
    exit(-1);
  }
  
  B->prime = p;
  B->next = NULL;
  B->index = 0;
  B->size = 0;
  B->extra = 0;
  
  B->bufferlock = malloc(sizeof(pthread_mutex_t));
  pthread_mutex_init(B->bufferlock, NULL);
  
  return B;
}

void free_buffer(buffer* B)
{
  if (B)
  {
    pthread_mutex_destroy(B->bufferlock);
  }
  free(B);
}

char add(buffer* B, unsigned long x)
{
  if (!B)
  {
    printf("{ error } This is not a buffer.\n");
    return 0;
  }
  
  if (B->size < BUFFERSIZE)
  {
    pthread_mutex_lock(B->bufferlock);
    B->buffer[(B->index + B->size) % BUFFERSIZE] = x;
    B->size += 1;
    pthread_mutex_unlock(B->bufferlock);
    return 1;
  }

  return 0;
}

unsigned long get(buffer* B)
{
  if (!B)
  {
    printf("{ error } This is not a buffer.\n");
    return 0;
  }
  
  if (B->size > 0)
  {
    pthread_mutex_lock(B->bufferlock);
    unsigned long x = B->buffer[B->index];
    B->index = (B->index + 1) % BUFFERSIZE;
    B->size -= 1;
    pthread_mutex_unlock(B->bufferlock);
    return x;
  }
  
  return 0;
}

void yield()
{
  if (sched_yield())
  {
    perror("yield");
  }
}
