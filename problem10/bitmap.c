#include <stdlib.h>

#include "bitmap.h"

#define BITS_PER_SEGM (sizeof(long) * 8)
#define N_SEGMENTS (BITMAP_SIZE / BITS_PER_SEGM + 1)

#define SEGMGET(X, D) ((X >> D) & 1)
#define SEGMSET(X, D, F) (X = ((F << D) | ((X >> D) << D) | (X % (1 << D))))

typedef unsigned long segment;

static segment segm[N_SEGMENTS];

void clear_bitmap()
{
  for (int i = 0; i < N_SEGMENTS; i++)
  {
    segm[i] = 0;
  }
}

bit  getbit(unsigned int d)
{
  unsigned int k = d / BITS_PER_SEGM;
  if (k >= N_SEGMENTS)
    return -1;
  
  return SEGMGET(segm[k], (d % BITS_PER_SEGM));
}

void setbit(unsigned int d, bit b)
{
  unsigned int k = d / BITS_PER_SEGM;
  if (k >= N_SEGMENTS)
    return;
  
  SEGMSET(segm[k], (d % BITS_PER_SEGM), b);
}

