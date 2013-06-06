#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sched.h>

#include "flagmap.h"

#define BITS_PER_FLAG 2
#define FLAGS_PER_INT (sizeof(int) * 8 / BITS_PER_FLAG)
#define INTS_PER_BLOCK 16
#define FLAGS_PER_BLOCK (sizeof(int) * 8 * INTS_PER_BLOCK / BITS_PER_FLAG)

/* Segment X, i.e. an unsigned int,
 * offset D, where 0 <= D < FLAGS_PER_INT,
 * flag F, where 0 <= F < (2 ^ BITS_PER_FLAG).
 * SEGMGET returns a FLAG, SEGMSET sets a FLAG. */
#define SEGMGET(X, D) SEGMGET2(X, (BITS_PER_FLAG * D))
#define SEGMGET2(X, BD) ((X >> BD) % (1 << BITS_PER_FLAG))
#define SEGMSET(X, D, F) SEGMSET2(X, (BITS_PER_FLAG * D), F)
#define SEGMSET2(X, BD, F) (X = (F << BD) | ((X >> BD) << BD) | (X % (1 << BD)))

/* Odd positive whole number N. 
 * PICKBLOCK determines which block N belongs to.
 * PICKSEGM determines which segment within its block N belongs to. */
#define ID(N) ((N / 2) - 1)
#define PICKBLOCK(N) PICKBLOCK2(ID(N))
#define PICKBLOCK2(I) (I / FLAGS_PER_BLOCK)
#define PICKSEGM(N) PICKSEGM(ID(N))
#define PICKSEGM2(I) ((I % FLAGS_PER_BLOCK) / FLAGS_PER_INT)
#define PICKOFFSET(N) PICKOFFSET2(ID(N))
#define PICKOFFSET2(I) (I % FLAGS_PER_INT)

typedef struct block
{
  unsigned int part[INTS_PER_BLOCK];
  pthread_mutex_t *blocklock;
} block;


