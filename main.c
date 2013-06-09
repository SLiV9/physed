#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    }
    printf("< end of file >\n\n");
    
    printf("The answer is unknown.\n");
    
    printf("\n\n[ done ]\n");

    return 0;
}
