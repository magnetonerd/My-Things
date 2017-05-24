/*********************************************************
 *This is an integrer division program. It is purely for
 *demonstration purposes. The function intdiv explicily
 *lays out what the mathematical behavior of division is
 *going to act like. There is no optimization in this
 *code. It can be optimized in one of two ways. Either
 *due the simple thing of just dividing two int's, or
 *by introducing bitwise operations.
 *********************************************************/

#include <stdio.h> //for printf and scanf

int intdiv(int numer, int denom); //function prototype

int main() //Simple driver instructing the program
{
  int numer; //numerator
  int denom; //denominator

  printf("What is the numerator?\n");
  scanf("%d", &numer); //user input
  printf("What is the denominator?\n");
  scanf("%d", &denom); //user input
  printf("The quotient is:\n");
  printf("%d\n", intdiv(numer, denom)); //Prints out quotient
  
  return 0;
}

/********************************************************
 *Basically, integer division is a truncation of real
 *number division, behaving as a linear iteration of
 *subtraction. Since we are focusing on the truncated
 *division, we are not going to be concerned with the
 *remainder of the division.
 *
 *To achieve this behavior we are going to start from 
 *the grade school definition of division:
 *
 *    n        performing truncation    n
 *   --- = m           ====>>          --- <= m
 *    a                                 a
 *
 *This gives us the form of the formula that we will
 *be implementing:
 *
 *                    n - a*m <= 0
 *
 *In order to find the value of m we must iterate through
 *all possible values until the formula is true. We 
 *accomplich this by using a while loop with it's
 *conditional being:
 *         
 *                    n > a*m
 *
 *This is initialized at m = 0, incrementing m by one
 *each time through the loop. Once the conditional is no
 *longer true the loop terminates.
 *
 *The main downside to this method is that the value of m
 *is going to be to large. so it must be decremented in 
 *order to get to the desired values.
 ********************************************************/

int intdiv(int numer, int denom)
{
  if(denom == 0) return 1; //No sir, we don't like this
  if(numer == 0) return 0; //zero divided by anything is zero
  if(numer < denom) return 0; //truncating a number smaller than one gives 0
    
  int count = 0; //initializing m = 0
  int subtractor = 0; //initializing a*m = 0
  
  while(numer > subtractor){  //main loop while(n > a*m)
    subtractor = denom*count; //instantiating a*m
    ++count; //incrementing m by one
  }

  if(numer - subtractor == 0) --count; //if a divides n evenly
  if(numer < subtractor) count -= 2;   //if a does not divide n evenly
  
  return count; //final result
}

