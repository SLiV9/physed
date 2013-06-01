#define BUFFERSIZE (1<<1)
#define MAXVALUE 1000000000
#define NPRIMES 100

#define FIRSTPRIME 5
#define PRIMEOFFSET 3

char IsRunning;

typedef struct buffer
{
  struct buffer *next;
  unsigned long buffer[BUFFERSIZE];
  unsigned long prime;
  unsigned int index, size;
  unsigned long extra;
  pthread_mutex_t *bufferlock;
} buffer;

void yield();

buffer* init_buffer(unsigned long p);
void free_buffer(buffer* B);

/* add() tries to add x to the buffer B. If this buffer is full, 0 is 
 * returned. If add() is succesful, a positive value is returned. */
char add(buffer* B, unsigned long x);

/* get() tries to retrieve a value from the buffer B. If the buffer is empty 
 * 0 is returned, otherwise an positive long is returned. */
unsigned long get(buffer* B);
