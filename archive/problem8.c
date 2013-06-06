#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 8 ]\n\n\n");
    
    char digit[1000];
    char bin[1];
    
    FILE* fdigits = fopen("data/problem8/digits.txt", "r");
    if (!fdigits)
    {
      perror("fopen error");
      return -1;
    }
    
    /* The file consists of 20 lines, each containing 50 digits. */
    for (int i = 0; i < 20; i++)
    {
      /* Read 50 digits from the file. */
      fread(&digit[50 * i], sizeof(char), 50, fdigits);
      /* Throw the newline character away. */
      fread(&bin, sizeof(char), 1, fdigits);
    }
    
    for (int i = 0; i < 1000; i++)
    {
      digit[i] = digit[i] - '0';
      printf("%d", (unsigned int) digit[i]);
      if ((i+1) % 50 == 0)
        printf("\n");
    }
    printf("\n");
    
    unsigned long current, greatest = 0;
    for (int i = 0; i < 996; i++)
    {
      if (digit[i] && digit[i+1] && digit[i+2] && digit[i+3] && digit[i+4])
      {
        if ((current = ((unsigned long) digit[i]) * digit[i+1] * digit[i+2] 
            * digit[i+3] * digit[i+4]))
        {
          if (current > greatest)
          {
            greatest = current;
          }
        }
      }
    }
    
    printf("The greatest product of 5 consecutive digits is %lu.\n", greatest);
    
    fclose(fdigits);

    printf("\n\n[ done ]\n");

    return 0;
}
