#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi  3.141592
#define MAX 201
#define MIN 0
double mu0 = 0.0000004*pi;
double R   = 1.0;
double V   = 10000.0;
double D   = 3.0;
double L   = 0.05;
double v0  = 200.0;

double sqr(double x);
double K1(double D, double s, double L);
double K2(double D, double s, double L);
double velocity(double b, double m, double K1, double K2);
double current(double b, double v, double K1);
double MagneticField(double b, double x, double s);
double magflux(double mfield,double s, double x);
double midpoint(double a, double b);
double difference(double a, double b);
double singleintegral(double dif_x[], double mid_x[]);
double MagneticFlux(double mid_x[], double h1, double mid_y[], double h2, double b);

int main()
{
  double m,s,b;

  m = 0.003;
  s = 0.001;
  double I0  = V/R;
  b = mu0*I0/(4.0*pi);
  printf("b:        %f\n", b);
  double k10, k20, vel, I;

  k10 = K1(D, s, L);
  printf("K1:       %f\n",k10);
  k20 = K2(D, s, L);
  printf("K2:       %f\n", k20);
  printf("K1*K2:    %f\n", k20*k10);
  vel = velocity(b, m, k10, k20);
  printf("velocity: %f\n", vel);
  I = current(b, vel, k10);
  printf("current:  %f\n", I);

  double x[MAX], s2[MAX], mfield[MAX][MAX], h1 = (double) (D/MAX), h2 = (double) (L/MAX);
  int i,j;
  for(i = 0; i < MAX; ++i){
    x[i] = (double) (i*h1);
    for(j = 0; j < MAX; ++j){
      s2[j] = (double) (j*h2);
      mfield[i][j] = MagneticField(b,x[i],s2[j]);
      printf("The field strength at x = %f and s = %f is %f T\n",x[i],s2[j],mfield[i][j]);
    }
  }

  double mid_x[MAX], mid_s[MAX];
  for(i = 1; i < MAX; ++i){
    mid_x[i-1] = midpoint(x[i],x[i-1]);
    mid_s[i-1] = midpoint(s2[i],s2[i-1]);
  }

  double mflux0[MAX][MAX], mflux1[MAX][MAX];
  for(i = 0; i < MAX; ++i){
    for(j = 0; j < MAX; ++j){
      mflux0[i][j] = magflux(mfield[i][j],s2[j],x[i]);
      mflux1[i][j] = MagneticFlux(mid_x, h1, mid_s, h2, b);
      printf("The flux at x = %f and s = %f is %f Tm^2\n",x[i],s2[j],mflux1[i][j]);
    }
  }
  
  
  return 0;
}

double sqr(double x)
{
  return x*x;
}

double K1(double D, double s, double L)
{
  double k11,A,B;

  A = sqr(D) + sqr(s);
  A = sqrt(A);
  B = sqr(D) + sqr((L-s));
  B = sqrt(B);
  
  k11 = 1/(s*A) +1/((L-s)*B);

  return k11;
}

double K2(double D, double s, double L)
{
  double k21,A,B;
  A = sqr(D) + sqr(s);
  A = sqrt(A);
  B = sqr(D) + sqr((L-s));
  B = sqrt(B);

  k21 = A/s + B/(L-s) -2;

  return k21;
}

double velocity(double b, double m, double K1, double K2)
{
  return -(sqr(b)*sqr(L)*D/(m*R))*K1*K2 + v0;
}

double current(double b, double v, double K1)
{
  return -(b*L*D*v/R)*K1;
}

double MagneticField(double b, double x, double s)
{
  return b*(x/(s*sqrt(sqr(x)+sqr(s))) + (D-x)/((L-s)*sqrt(sqr((D-x))+sqr((L-s)))));
}

double magflux(double mfield, double s, double x)
{
  return mfield*s*x;
}

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

/*
double singleintegral(double dif_x[], double mid_x[])
{
  double igral = 0.0;
  int i;

  for(i = MIN; i < MAX; ++i){
    igral = igral + dif_x[i]*function1(mid_x[i]);
  }
  return igral;
}
*/

double MagneticFlux(double mid_x[], double h1, double mid_y[], double h2, double b)
{
  double igral2 = 0.0;
  int i,j;

  for(i = MIN; i < MAX; ++i){
    for(j = MIN; j < MAX; ++j){
      igral2 = igral2 + h2*MagneticField(b,mid_x[j],mid_y[i]);
    }
  }
  igral2 = igral2*h1;
  return igral2;
}
