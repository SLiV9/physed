#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATA(x,y) data[20 * (y) + (x)]

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 11 ]\n\n\n");
    
    char buffer[4] = "\0\0\0\0";
    int data[400];
    
    FILE* fdigits = fopen("data/problem11/data.txt", "r");
    if (!fdigits)
    {
      perror("fopen error");
      return -1;
    }
    
    printf("Input:\n");
    /* The file consists of 400 lines, seperated by either a space or a newline 
     * character. */
    for (int i = 0; i < 400; i++)
    {
      fread(buffer, sizeof(char), 3, fdigits);
      printf("%s", buffer);
      
      data[i] = ((int) buffer[0] - '0') * 10 + buffer[1] - '0';
    }
    printf("< end of file >\n\n");
    
    printf("Numbers:\n");
    for (int y = 0; y < 20; y++)
    {
      for (int x = 0; x < 20; x++)
      {
        printf("%d ", DATA(x,y));
      }
      printf("\n");
    }
    printf("< end of data >\n\n");
    
    int prod, greatest_product = 0;
    
    /* Horizontal groups. */
    for (int y = 0; y < 20; y++)
    {
      for (int x = 0; x < 16; x++)
      {
        prod = DATA(x,y) * DATA(x+1,y) * DATA(x+2,y) * DATA(x+3,y);
        if (prod > greatest_product)
        {
          greatest_product = prod;
        }
      }
    }
    
    /* Vertical groups. */
    for (int y = 0; y < 16; y++)
    {
      for (int x = 0; x < 20; x++)
      {
        prod = DATA(x,y) * DATA(x,y+1) * DATA(x,y+2) * DATA(x,y+3);
        if (prod > greatest_product)
        {
          greatest_product = prod;
        }
      }
    }
    
    /* Diagonal-down groups. */
    for (int y = 0; y < 16; y++)
    {
      for (int x = 0; x < 16; x++)
      {
        prod = DATA(x,y) * DATA(x+1,y+1) * DATA(x+2,y+2) * DATA(x+3,y+3);
        if (prod > greatest_product)
        {
          greatest_product = prod;
        }
      }
    }
    
    /* Diagonal-up groups. */
    for (int y = 3; y < 20; y++)
    {
      for (int x = 0; x < 16; x++)
      {
        prod = DATA(x,y) * DATA(x+1,y-1) * DATA(x+2,y-2) * DATA(x+3,y-3);
        if (prod > greatest_product)
        {
          greatest_product = prod;
        }
      }
    }
    
    printf("The greatest product is %d.\n", greatest_product);
    
    printf("\n\n[ done ]\n");

    return 0;
}
