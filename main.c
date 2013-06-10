#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 15
#define VAL(x,y) data[SIZE * (y) + (x)]

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problems 18 & 67 ]\n\n\n");
    
    char data[SIZE * SIZE];
    char buffer[2];
    char bin[1];
    
    FILE* fdata = fopen("data/problem18/triangle.txt", "r");
    for (int y = 0; y < SIZE; y++)
    {
      for (int x = 0; x <= y; x++)
      {
        fread(buffer, sizeof(char), 2, fdata);
        fread(bin, sizeof(char), 1, fdata);
        
        VAL(x,y) = 10 * (buffer[0] - '0') + buffer[1] - '0';
      }
    }
    fclose(fdata);
    
    for (int y = 0; y < SIZE; y++)
    {
      for (int x = 0; x <= y; x++)
      {
        printf("%d%d ", (int) VAL(x,y) / 10, (int) VAL(x,y) % 10);
      }
      printf("\n");
    }
    
    printf("\n\n[ done ]\n");

    return 0;
}
