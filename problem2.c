#include <stdio.h>

#define LIMIT 4000000

static int a, b;
static unsigned long sum;

int next()
{
    // ..., a, b, c, ...
    int c = a + b;
    a = b;
    b = c;
    return c;
}

void problem2()
{
    printf("Problem 2.\n");

    a = 1;
    b = 2;
    sum = 0;
    do
    {
        if (b % 2 == 0)
            sum += b;
    }
    while (next() <= LIMIT);

    printf("Answer: %lu.\n", sum);
}
