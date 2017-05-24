#define MAX 200
#define MIN 0
#define EPSILON 1.0e-15
#define DELTA 1.0e-18

double midpoint(double a, double b);
double difference(double a, double b);
double singleintegral(double dif_x[], double mid_x[]);
double doubleintegral(double dif_x[], double mid_x[], double dif_y[], double mid_y[]);
double simpleintegral(double x, double delta_x);

double midpoint(double a, double b)
{
  double mid;
  mid = (b-a)/2.0;
  return mid;
}

double difference(double a, double b)
{
  double diff;
  diff = b-a;
  return diff;
}

double singleintegral(double dif_x[], double mid_x[])
{
  double igral = 0.0;
  int i;

  for(i = MIN; i < MAX; ++i){
    igral = igral + dif_x[i]*function1(mid_x[i]);
  }
  return igral;
}

double doubleintegral(double dif_x[], double mid_x[], double dif_y[], double mid_y[])
{
  double 2igral = 0.0;
  int i,j;

  for(i = MIN; i < MAX; ++i){
    for(j = MIN; j < MAX; ++j){
      2igral = 2igral + dif_y[j]*function2(mid_x[j],mid_y[i]);
    }
  }
  2igral = 2igral*dif_x[MAX-1];
  return 2igral;
}

double simpleintegral(double x, double delta_x)
{
  return function(DELTA)*2*EPSILON-(function(x+EPSILON)-function(x-EPSILON))*delta_x;
}
