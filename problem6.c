#include <stdio.h>

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 6 ]\n\n\n");
    
    long sumofsquares = 0, sum = 0, squareofsum = 0;
    for (unsigned int n = 1; n <= 100; n++)
    {
      sum += n;
      sumofsquares += n * n;
    }
    squareofsum = sum * sum;
    
    long difference = sumofsquares - squareofsum;
    printf("(1*1 + ... + 100*100) = %ld\n"
      "(1 + ... + 100)^2 = %ld\n"
      "%ld - %ld = %ld", sumofsquares, squareofsum, sumofsquares, squareofsum,
      difference);

    printf("\n\n[ done ]\n");

    return 0;
}
