#include <stdio.h>

/* We know that 10,000 <= c < 1,000,000. 
 * So c has either 6 or 5 digits. */
#define isPalindrome(X) ((X >= 100000 && (X / 100000 == X % 10) && \
  ((X / 10000) % 10 == (X / 10) % 10) && ((X / 1000) % 10 == (X / 100) % 10)) \
  || ((X / 10000 == X % 10) && ((X / 1000) % 10 == (X / 10) % 10)))

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 4 ]\n\n\n");
    
    int a, b, c;
    int highest_p = 9009; // the current highest palindrome
    int highest_a = 99; // its a component
    int highest_b = 91; // its b component
    
    for (a = 999; a > 99; a--)
    {
      if (a * a <= highest_p)
      {
        // u * v <= p for all u, v <= a.
        break;
      }
        
      for (b = a; b > 1; b--)
      {
        c = a * b;
        
        if (c <= highest_p)
        {
          // a * v <= p for all v <= b.
          break;
        }
          
        if (isPalindrome(c))
        {
          highest_p = c;
          highest_a = a;
          highest_b = b;
        }
      }
    }
    
    printf("Highest palindrome number that is the product of 3 digit numbers:\n"
      "%d x %d = %d\n", highest_a, highest_b, highest_p);

    printf("\n\n[ done ]\n");

    return 0;
}
