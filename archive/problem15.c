#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NPATHS(x,y) npaths[22 * (y) + (x)]

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 15 ]\n\n\n");
    
    unsigned long npaths[22 * 22];
    for (int u = 0; u < 22 * 22; u++)
    {
      npaths[u] = 0;
    }
    NPATHS(20, 20) = 1;
    
    for (int y = 20; y >= 0; y--)
    {
      for (int x = 20; x >= 0; x--)
      {
        NPATHS(x,y) += NPATHS(x+1,y) + NPATHS(x,y+1);
      }
    }
    
    for (int y = 0; y <= 20; y++)
    {
      printf("[ ");
      for (int x = 0; x <= 20; x++)
      {
        printf("%lu ", NPATHS(x,y));
      }
      printf("]\n");
    }
    
    printf("There are %lu lattice paths.\n", NPATHS(0,0));
    
    printf("\n\n[ done ]\n");

    return 0;
}
