#define BITMAP_SIZE 1000

typedef char bit;

void clear_bitmap();
void print_bitmap();

bit  getbit(unsigned int d);
void setbit(unsigned int d, bit b);

unsigned int find(unsigned int d, bit b);
