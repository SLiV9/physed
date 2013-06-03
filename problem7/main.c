#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "buffer.h"
#include "genny.h"
#include "sieve.h"

static buffer *first, *last;
static unsigned int threads_spawned;
static pthread_t PT[NTHREADS];
static pthread_t Genny;
static pthread_attr_t ptattr;

/* The spawn thread macro creates a thread and assigns a buffer to it. */
void spawn_thread(buffer* B)
{
  printf("Spawning thread %d.\n", threads_spawned);
  if (pthread_create(&PT[threads_spawned], &ptattr, &sieve, B))
  {
    printf("{ fatal error } Could not create pthread %d.\n", 
        threads_spawned);
    exit(-1);
  }
  threads_spawned += 1;
}

/* The main thread method. */
int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 7 ]\n\n\n");
    
    unsigned long last_prime, highest_prime = 5;
    unsigned int prime_index = 3;
    
    IsRunning = 1;
    threads_spawned = 0;
    
    first = init_buffer(highest_prime);
    last = init_buffer(0);
    first->next = last;
  
    pthread_attr_init(&ptattr);
    pthread_attr_setscope(&ptattr, PTHREAD_SCOPE_SYSTEM);
    
    if (pthread_create(&Genny, &ptattr, &generate, first))
    {
      printf("{ fatal error } Could not create pthread Genny.\n");
      exit(-1);
    }
    spawn_thread(first);
    
    while (highest_prime < MAXVALUE && prime_index < NPRIMES)
    {
      last_prime = get(last);
      if (last_prime)
      {
        if (last_prime <= highest_prime)
        {
          printf("Last prime %lu is less than highest prime %lu!\n",
              last_prime, highest_prime);
          IsRunning = 0;
          break;
        }
        
        highest_prime = last_prime;
        prime_index++;
        printf("%d\t -\t %lu\n", prime_index, highest_prime);
        if (highest_prime < MAXVALUE && prime_index < NPRIMES)
        {
          buffer* b = init_buffer(0);
          pthread_mutex_lock(last->bufferlock);
          last->next = b;
          last->prime = last_prime;
            printf("\t[");
            for (int j = 0; j < last->size; j++)
            {
              printf("\t %lu", last->buffer[(last->index + j) % BUFFERSIZE]);
            }
            printf("\t |");
            for (int j = last->size; j < BUFFERSIZE; j++)
            {
              printf("\t %lu", last->buffer[(last->index + j) % BUFFERSIZE]);
            }
            printf("\t] & %lu\n", last->extra);
          pthread_mutex_unlock(last->bufferlock);
          if (threads_spawned < NTHREADS)
          {
            spawn_thread(last);
          }
          last = b;
        }
      }
      else
      {
        yield();
      }
    }
    printf("\n\n");
    
    IsRunning = 0;
    
    if (pthread_join(Genny, NULL))
    {
      printf("{ error } Could not join pthread Genny.\n");
    }
    for (int i = 0; i < NTHREADS; i++)
    {
      if (pthread_join(PT[i], NULL))
      {
        printf("{ error } Could not join pthread %d.\n", i);
      }
    }
    
    printf("The %uth prime is %lu.\n", prime_index, highest_prime);
    
    printf("\n");
    int i = 3;
    buffer* b = first;
    while (b)
    {
      printf("%d\t -\t %lu\n", i, b->prime);
      printf("\t[");
      for (int j = 0; j < b->size; j++)
      {
        printf("\t %lu", b->buffer[(b->index + j) % BUFFERSIZE]);
      }
      printf("\t |");
      for (int j = b->size; j < BUFFERSIZE; j++)
      {
        printf("\t %lu", b->buffer[(b->index + j) % BUFFERSIZE]);
      }
      printf("\t] & %lu\n", b->extra);
      b = b->next;
      i++;
    }
    printf("\n");
    
    //i = 3;
    buffer* b1 = first;
    buffer* b2;
    while (b1)
    {
      //printf("\t %d", i);
      b2 = b1->next;
      free(b1);
      b1 = b2;
      //i++;
    }
    printf("\n");
  
    pthread_attr_destroy(&ptattr);
    
    printf("The %uth prime is %lu.\n", prime_index, highest_prime);

    printf("\n\n[ done ]\n");

    return 0;
}
