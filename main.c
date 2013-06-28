#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NNAMES 6000
#define MAXLEN 12

typedef char name[MAXLEN];

name list[NNAMES];

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem ]\n\n\n");
    
    FILE* fnames = fopen("data/problem22/names.txt", "r");
    if (!fnames)
    {
      perror("fopen error");
      return -1;
    }
    
    unsigned int itm = 0, pos = 0;
    char c;
    
    do
    {
      c = fgetc(fnames);
      
      if (c == ',' || c == EOF)
      {
        list[itm][pos] = '\0';
        itm++;
        pos = 0;
      }
      else if (c != '"')
      {
        list[itm][pos] = c;
        pos++;
      }
    }
    while (c != EOF);
    
    fclose(fnames);
    
    printf("Names:\t\t");
    for (int i = 0; i < NNAMES; i++)
    {
      if (strlen(list[i]) == 0)
        break;
      printf("%12s,\t", list[i]);
    }
    printf("\tend.\n");
    
    printf("\n\n[ done ]\n");

    return 0;
}
