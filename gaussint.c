#include <stdio.h>
#include <math.h>

#define pi acos(-1.0)

void gaussxw(int N, double x[], double w[], double x1, double x2)
{
  int n,k;
  double big,small,z,zp;
  double a,p0,p1,p2,dP,dx;
  double EPS = 1e-15;
  double delta = 1.0, *delta_ptr = &delta;

  big = 0.5*(x2+x1);
  small = 0.5*(x2-x1);
  
  for(n = 0; n < N; ++n){
    a = (double) (4*(n+1)-1)/(4*N+2);
    z = cos(pi*a);

    while (delta>EPS){
      p0 = 1.0;
      p1 = z;
      for(k = 1; k <= N; ++k){
	p2 = p0;
	p0 = p1;
	p1 = ((2*k+1)*z*p1-k*p2)/(k+1);
      }
      dP = (N+1)*(z*p1-p0)/(z*z - 1);
      dx = p1/dP;
      z -= dx;
      *delta_ptr = fabs(dx);
      //printf("%f\n",delta);
    }
    w[n] = 2/((1-z*z)*dP*dP);
    //w[N+1-n] = w[n];
    x[n] = small*z+big;
    //x[N+1-n] = 0.5*(x2-x1)*z+0.5*(x2+x1);
    w[n] = small*w[n];
    //w[N+1-n] = w[n];
  }
}

double f(double x)
{
  return x*x*x*x - 2.0*x + 1.0;
}

int main()
{
  int i, N = 100;
  double a = 0.0;
  double b = 2.0;
  double x[N],w[N];

  gaussxw(N,x,w,a,b);
  
  double total = 0.0;
  for(i = 0; i < N; ++i){
    total += w[i]*f(x[i]);
    printf("i = %d, x = %f, w = %1.9f\n",i,x[i],w[i]);
  }
  
  printf("%1.9f\n",total);
  
  return 0;
}
