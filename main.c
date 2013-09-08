#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NNAMES 60
#define WORDSIZE 12

typedef char word[WORDSIZE];

word name[NNAMES];
unsigned int alpha[NNAMES];
unsigned int order[NNAMES];
unsigned int nNames = 0;

void print_names()
{
  printf("Names:\t\t");
  for (int i = 0; i < nNames; i++)
  {
    printf("%12s,\t", name[i]);
  }
  printf("\tend.\n");
}

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem ]\n\n\n");
    
    memset(alpha, 0, sizeof(unsigned int) * NNAMES);
    
    /* Open the file. */
    
    FILE* fnames = fopen("data/problem22/names.txt", "r");
    if (!fnames)
    {
      perror("fopen error");
      return -1;
    }
    
    /* Read all of the words. */
    printf("Reading...\n");
    unsigned int fuckme = 100000;
    while (!feof(fnames) && nNames < NNAMES && fuckme)
    {
      word bfr;
      fscanf(fnames, "%*[^a-zA-Z]");
      if (fscanf(fnames, "%12[a-zA-Z]", bfr))
      {
        strcpy(name[nNames], bfr);
        alpha[nNames] = 0;
        for (int t = 0; t < WORDSIZE; t++)
        {
          alpha[nNames] += (bfr[t] - 'A' + 1);
        }
        order[nNames] = nNames + 1;
        nNames++;
      }
      
      fuckme--;
    }
    printf("Read %u words.\n", nNames);
    
    fclose(fnames);
    
    print_names();
    
    /* Calculate the order / 'alphabetise'. */
    
    
    
    printf("\n\n[ done ]\n");

    return 0;
}
