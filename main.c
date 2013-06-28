#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Year is the actual year, i.e. 1900, 1993, 2013 etc.
 * Month is the month where JAN = 0, DEC = 11, 12 = 0.
 * Day is the day since 31 dec 1899, where Day 1 = 1 Jan 1900, a Monday. */
typedef int year;
typedef enum { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC }
    month;
typedef unsigned int day;

/* A leap year is divisible by 4, but not divisible by 100 unless divisible by 
 * 400. I.e.: a leap year is (divisible by 4) AND ((not divisible by 100)
 * OR (divisible by 400)). I.e., if divisible by 100, a leap year is divisible 
 * by 400 (and therefore by 4); otherwise, a leap year is divisible by 4. */
char isLeap(year Y)
{
  if (Y % 100)
    Y = Y % 100;
    
  return (Y % 4 == 0);
}

/* Determine the days of this month. */
char daysOfMonth(month M, year Y)
{
  static char daysPerMonth[] = { 31, 0, 31, 30, 31, 30, 
      31, 31, 30, 31, 30, 31 };
  
  if (M != FEB)
  {
    return daysPerMonth[M];
  }
  else
  {
    return (char) 28 + (isLeap(Y));
  }
}

/* Determine if a day is a Sunday, knowing that Day 1, 1 Jan 1900, is a 
 * Monday. */
char isSunday(day D)
{
  return (D % 7 == 0);
}

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem ]\n\n\n");
    
    day x = 1;
    month m = JAN;
    year y = 1900;
    
    x += daysOfMonth(m, y);
    
    printf("\n\n[ done ]\n");

    return 0;
}
