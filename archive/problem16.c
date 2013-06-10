#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMBERSIZE 302

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
    printf("[ Project Euler: Problem 16 ]\n\n\n");
    
    number old, new;
    memset(old, 0, NUMBERSIZE);
    memset(new, 0, NUMBERSIZE);
    old[0] = 1;
    
    for (int count = 0; count < 1000; count++)
    {
      //print_number(old);
      
      char d = 0, f = 0;
      for (int t = 0; t < NUMBERSIZE; t++)
      {
        d = 2 * old[t] + f;
        new[t] = (d % 10);
        f = d / 10;
      }
    
      memcpy(old, new, NUMBERSIZE);
      memset(new, 0, NUMBERSIZE);
    }
    
    printf("\n2^1000 = ");
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
