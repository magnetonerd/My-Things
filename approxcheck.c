/*****************************************************************************************************************
 * This program is intended to calculate the sum of the natural log of values from one upto a given value, MAX.  *
 * It does this by continuously updating the value that is stored in the memory location for the variable total  *
 * Another property of this program is that it calculates the approximation of this summation by way of integr-  *
 * ation. After calculating the above mentioned values the program then figures out the percent error of the     *
 * two calculations. This demonstrates that for sufficiently small values of MAX-above 62- the approximate       *
 * value is a very good approximation to the true value.                                                         *
 *                                                                                                               *
 * Psuedo-code:                                                                                                  *
 *                                                                                                               *
 * Preprocess:                                                                                                   *
 *     SET MAX = 63                                                                                              *
 *     define approx(n) as n*ln(n)-n+1                                                                           *
 * Declarations:                                                                                                 *
 *     integer i                                                                                                 *
 *     real number total = 0.0                                                                                   *
 *     real number p_error                                                                                       *
 * Pointers:                                                                                                     *
 *     Ptotal = address of total                                                                                 *
 * MAIN FUNC:                                                                                                    *
 *     for i = 1..MAX:                                                                                           *
 *         deref Ptotal = deref Ptotal + ln(i)                                                                   *
 *     p_error = (total - approx(MAX))/total                                                                     *
 *     Write(MAX, total, approx(MAX), p_error)                                                                   *
 *****************************************************************************************************************/
#include <stdio.h> //To be able to use printf()                                                                  
#include <math.h>  //To be able to use log()                                                                     

#define MAX 200000                                                                                                
#define approx(n) (n*log(n)-n+1) //result of integral of ln(x) evaluated from 1 to n                             

int main()                                                                                                        
{                                                                                                                 
  int i; //incrementer                                                                                            
  double total = 0.0; //summation value                                                                           
  double *ptotal = &total; //ptotal has the address of total                                                      
  double p_error; //percent error                                                                                 

  for(i = 1; i <= MAX; ++i) *ptotal += log(i); //incrementing the value at ptotal by ln(i)                        
  
  p_error = (total - approx(MAX))/total;                                                                          
  printf("max is %d total is %5f approx is %5f the percent error is %5f\n", MAX, total, approx(MAX), p_error*100);
}
