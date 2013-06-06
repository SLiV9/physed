#define BITS_PER_FLAG 2
#define FLAGS_PER_INT (sizeof(int) * 8 / BITS_PER_FLAG)
#define INTS_PER_BLOCK 16
#define FLAGS_PER_BLOCK (sizeof(int) * 8 * INTS_PER_BLOCK / BITS_PER_FLAG)

#define SEGMGET(X, D) SEGMGET2(X, (BITS_PER_FLAG * D))
#define SEGMGET2(X, BD) ((X >> BD) % (1 << BITS_PER_FLAG))
#define SEGMSET(X, D, F) SEGMSET2(X, (BITS_PER_FLAG * D), F)
#define SEGMSET2(X, BD, F) (X = (F << BD) | ((X >> BD) << BD) | (X % (1 << BD)))

typedef struct block
{
  unsigned int part[INTS_PER_BLOCK];
} block;
