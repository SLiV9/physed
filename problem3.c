#include <stdio.h>

void problem3()
{
    printf("Problem 3.\n");

    unsigned long long x = 600851475143LL;
    unsigned long long d = 3;
    printf("x = %llu, d = %llu.\n", x, d);

    while (d * d <= x)
    {
        if (x % d == 0)
            x /= d;
        else
            d += 2;
        printf("x = %llu, d = %llu.\n", x, d);
    }

    printf("Answer: %llu.\n", x);
}

