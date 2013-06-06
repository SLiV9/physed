#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

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

/* Index, D, where 0 <= D.
 * PICKBLOCK determines which block D belongs to.
 * PICKSEGM determines which segment within its block D belongs to. */
#define PICKBLOCK(D) (D / FLAGS_PER_BLOCK)
#define PICKSEGM(D) ((D % FLAGS_PER_BLOCK) / FLAGS_PER_INT)
#define PICKOFFSET(D) (D % FLAGS_PER_INT)

typedef struct block
{
  unsigned int part[INTS_PER_BLOCK];
  pthread_mutex_t *blocklock;
} block;

static int nBlocks;

char get_flag_in_block(block *B, unsigned int d)
{
  return WRONG;
}

char set_flag_in_block(block* B, unsigned int d)
{
  return WRONG;
}

char get_flag(unsigned int d)
{
  if (PICKBLOCK(d) >= nBlocks)
  {
  return WRONG;
  }
  
  return WRONG;
}

char set_flag(unsigned int d, char f)
{
  if (PICKBLOCK(d) >= nBlocks)
  {
  return WRONG;
  }
  
  return WRONG;
}
