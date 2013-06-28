#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int d(int n)
{
  int sum = 1;
  int i;
  
  for (i = 2; i * i < n; i++)
  {
    if (n % i == 0)
    {
      sum += i;
      sum += n / i;
    }
  }
  
  if (i * i == n)
    sum += i;
  
  return sum;
}

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem ]\n\n\n");
    
    int sum = 0;
    
    for (int x = 1; x < 10000; x++)
    {
      int y = d(x);
      if (y > x)
      {
        if (d(y) == x)
        {
          sum += x;
          sum += y;
        }
      } 
    } 
    
    printf("Answer: %i.\n", sum);
    
    printf("\n\n[ done ]\n");

    return 0;
}
