#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 9 ]\n\n\n");
    
    /* We are looking for A, B, C such that 0 < A < B < C < 1000,
     * where A + B + C = 1000 and A*A + B*B == C*C. Truths:
     * A < 1000 / 3 = 333 and 2B < B+C = 1000 - A. */
    unsigned long a, b, c, A, B, C;
    
    char done = 0;
    for (a = 1; !done && a < 333; a++)
    {
      for (b = a + 1; !done && b < (1000 - a) / 2; b++)
      {
        c = 1000 - a - b;
        
        done = (a*a + b*b == c*c);
        if (done)
        {
          A = a;
          B = b;
          C = c;
        }
      }
    }
    
    if (done)
    {
      printf("a = %lu, b = %lu, c = %lu.\n", A, B, C);
      printf("Their product: abc = %lu.\n", A * B * C);
    }
    else
    {
      printf("No such triplet found.\n");
    }

    printf("\n\n[ done ]\n");

    return 0;
}
