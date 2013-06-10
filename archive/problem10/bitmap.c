#include <stdio.h>

#include "bitmap.h"

typedef unsigned long segment;

#define BITS_PER_SEGM (sizeof(long) * 8)
#define N_SEGMENTS (BITMAP_SIZE / BITS_PER_SEGM + 1)

#define SEGMGET(X, D) ((X >> D) & 1)
#define SEGMSET(X, D, F) (X = \
    (((segment) F << D) | ((X >> D) << D) | (X % ((segment) 1 << D))))

static segment segm[N_SEGMENTS];

void clear_bitmap()
{
  for (int i = 0; i < N_SEGMENTS; i++)
  {
    segm[i] = 0;
  }
}

void print_bitmap()
{
  segment printer = 0;
  
  printf("[[\n");
  for (int i = 0; i < N_SEGMENTS; i++)
  {
    printer = segm[i];
    
    printf("\t :");
    for (int z = 0; z < BITS_PER_SEGM; z++)
    {
      printf("%d", (unsigned int) (printer & 1));
      printer = printer >> 1;
    }
    printf(": \n");
  }
  printf("]]\n");
}

bit  getbit(unsigned int d)
{
  unsigned int k = d / BITS_PER_SEGM;
  if (k >= N_SEGMENTS)
  {
    printf("{ bitmap fault } Index %d out of bounds.\n", d);
    return -1;
  }
  
  return SEGMGET(segm[k], (d % BITS_PER_SEGM));
}

void setbit(unsigned int d, bit b)
{
  unsigned int k = d / BITS_PER_SEGM;
  if (k >= N_SEGMENTS)
  {
    printf("{ bitmap fault } Index %d out of bounds.\n", d);
    return;
  }
  
  SEGMSET(segm[k], (d % BITS_PER_SEGM), b);
}

/* Find the bit that is set to b. */
unsigned int find(unsigned int d, bit b)
{
  for (unsigned int u = d; u < BITMAP_SIZE; u++)
  {
    if (getbit(u) == b)
    {
      return u;
    }
  }
  
  return ((unsigned int) -1);
}

