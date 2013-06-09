#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIGIT(i, t) data[50 * (i) + (t)]

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 13 ]\n\n\n");
    
    char data[5000];
    char bin;
    
    FILE* fdigits = fopen("data/problem13/numbers.txt", "r");
    if (!fdigits)
    {
      perror("fopen error");
      return -1;
    }
    
    /* The file consists of 100 lines, each containing a 50 digit number. */
    for (int i = 0; i < 100; i++)
    {
      fread(&data[50 * i], sizeof(char), 50, fdigits);
      fread(&bin, sizeof(char), 1, fdigits);
    }
    
    for (int u = 0; u < 5000; u++)
    {
      data[u] -= '0';
    }
    
    printf("Numbers:\n");
    for (int i = 0; i < 100; i++)
    {
      for (int t = 0; t < 50; t++)
      {
        printf("%d", (int) DIGIT(i, t));
      }
      printf("\n");
    }
    printf("< end of data >\n\n");
    
    printf("The answer is unknown.\n");
    
    printf("\n\n[ done ]\n");

    return 0;
}
