#define BUFFERSIZE (1<<8)

/* A FIFO buffer for storing natural (i.e. positive whole) numbers. */
typedef struct buffer
{
  unsigned long data[BUFFERSIZE];
  unsigned int index, size;
  pthread_mutex_t *bufferlock;
} buffer;

/* Memory handling and initialisation. */
buffer* init_buffer();
void free_buffer(buffer* B);

/* add() tries to add x to the buffer B. If this buffer is full, 0 is 
 * returned. If add() is succesful, a positive value is returned. */
char add(buffer* B, unsigned long x);

/* get() tries to retrieve a value from the buffer B. If the buffer is empty 
 * 0 is returned, otherwise an positive long is returned. */
unsigned long get(buffer* B);
