#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMBERSIZE 1000

typedef char number[NUMBERSIZE];

void print_number(number N)
{
  printf("0x");
  for (int t = NUMBERSIZE-1; t >= 0; t--)
  {
    printf("%d", (int) N[t]);
  }
  printf("\n");
}

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem ]\n\n\n");
    
    number old, new;
    memset(old, 0, NUMBERSIZE);
    memset(new, 0, NUMBERSIZE);
    old[0] = 1;
    
    /* We can ignore 100, since it does not add any digits apart from two 0's.*/
    for (int x = 2; x < 100; x++)
    {
      int d = 0, f = 0;
      for (int t = 0; t < NUMBERSIZE; t++)
      {
        d = x * old[t] + f;
        new[t] = (char) (d % 10);
        f = d / 10;
      }
      
      memcpy(old, new, NUMBERSIZE);
      memset(new, 0, NUMBERSIZE);
    }
    
    printf("100! = ");
    print_number(old);
    
    int sum = 0;
    
    for (int t = 0; t < NUMBERSIZE; t++)
    {
      sum += old[t];
    }
    
    printf("\nThe answer is %d.\n", sum);
    
    printf("\n\n[ done ]\n");

    return 0;
}
