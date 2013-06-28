#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NNAMES 6000
#define MAXLEN 12

typedef char name[MAXLEN];

name list[NNAMES];
int alpha[NNAMES];
unsigned int nNames = 0;

void print_names()
{
  printf("Names:\t\t");
  for (int i = 0; i < nNames; i++)
  {
    printf("%12s,\t", list[i]);
  }
  printf("\tend.\n");
}

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem ]\n\n\n");
    
    /* Reading the names from the file. */
    
    FILE* fnames = fopen("data/problem22/names.txt", "r");
    if (!fnames)
    {
      perror("fopen error");
      return -1;
    }
    
    unsigned int pos = 0;
    char c;
    
    do
    {
      c = fgetc(fnames);
      
      if (c == ',' || c == EOF)
      {
        list[nNames][pos] = '\0';
        alpha[nNames] = 0;
        nNames++;
        pos = 0;
      }
      else if (c != '"')
      {
        list[nNames][pos] = c;
        pos++;
      }
    }
    while (c != EOF);
    
    fclose(fnames);
    
    print_names();
    
    /* Alphabatise the list of names. */
    
    
    
    printf("\n\n[ done ]\n");

    return 0;
}
