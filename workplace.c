#include <stdio.h>
#include <math.h>

double fact(double x);
double comb(double x, double y);
long double my_pow(double x, double y);
double probability(double n, double k, double x, double y);
double first_moment(double n, double x, double y);
double second_moment(double n, double x, double y);
double stdev(double second, double first);

int main()
{
  double Num_Employ, Num_Manage, Num_Men, Num_Women;
  double Perct_Men, Perct_Women;

  Num_Employ = 3200.0;
  Num_Manage = 250.0;
  Perct_Men = 0.9;
  Perct_Women = 1.0 - Perct_Men;
  Num_Men = Perct_Men*Num_Employ;
  Num_Women = Perct_Women*Num_Employ;

  printf("%5f percent of your staff are Men\n", Perct_Men);
  printf("%5f percent of your staff are Women\n", Perct_Women);
  printf("There are %5f Men working for you\n", Num_Men);
  printf("There are %5f Women working for you\n", Num_Women);
  printf("\n");
  printf("%Lf* f\n", */ my_pow(Perct_Men,(Num_Manage-25.0)));
  
  double sum = 0.0;
  int i;

  for(i = 0; i <= (int)Num_Manage; ++i){
    //printf("%5f\n", probability(Num_Manage, (double)i, Perct_Men, Perct_Women));
    //sum += probability(Num_Manage, (double)i, Perct_Men, Perct_Women);
  }

  //printf("%5f\n",sum);
  
  return 0;
}

double fact(double x)
{
  if(x == 0.0){
    return 1.0;
  }else{
    return exp(gamma(x + 1.0));
  }
}

double comb(double x, double y)
{
  return fact(x)/(fact(y)*(fact(x-y)));
}

long double my_pow(double x, double y)
{
  long double prod = 1.0;
  int i;

  for(i = 0; i < (int)y; ++i){
    prod *= x;
  }
  return prod;
}

double probability(double n, double k, double x, double y)
{
  return comb(n,k)*pow(x,(n-k))*pow(y,k);
}

double first_moment(double n, double x, double y)
{
  int i;
  double total = 0.0;
  
  for(i = 0; i <= (int)n; ++i){
    total += i*probability(n,(double)i,x,y);
  }
  return total;
}

double second_moment(double n, double x, double y)
{
  int i;
  double total = 0.0;
  
  for(i = 0; i <= (int)n; ++i){
    total += pow(i,2)*probability(n,(double)i,x,y);
  }
  return total;
}

double stdev(double second, double first)
{
  return sqrt(second - pow(first,2));
}
