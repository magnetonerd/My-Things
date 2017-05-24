#include <stdio.h>
#include <math.h>

#define PI acos(-1.0)
#define ERR 3.0e-11

void gaussxw(double *xk[], double *w[], double a, double b, int N)
{
  int i,j,k;
  double xkp[N], x, xp, dx, P0, P1, der_P;//Pk[N], der_Pk[N];
  double scale_pos = 0.5*(b+a);
  double scale_neg = 0.5*(b-a);
  
  for(k = 1; k <= (N+1)/2; k++){
    x = cos(PI * ((4*k-1)/(4*N+2)));
    do{
      P0 = 1.0;
      P1 = x;
      //Pk[0] = 1.0;
      //Pk[1] = x;
      for(j = 1; j <= N; ++j){
	P0 = P1;
	P1 = ((2*j+1)*x*P1 - j*P0)/(j + 1);
	der_P = j*(x*P1 - P0)/(x*x - 1.0);
	//Pk[j] = ((2*j + 1)/(j + 1))*x*Pk[j-1] - (j/(j+1))*Pk[j-2];
	//der_Pk[j-1] = k*(x*Pk[j-1] - Pk[j-2])/(x*x - 1.0);
      }
      dx = P1/der_P;//Pk[N]/der_Pk[N];
      x -= dx;
    }while(dx > ERR); 
    *xk[k] = scale_neg*x + scale_pos;
    *xk[N+1-k] = scale_neg*x + scale_pos;
    *w[k] = 2/((1-x*x)*der_P*der_P);//*der_Pk[N]*der_Pk[N]);
    *w[N+1-k] = *w[k];
  }
}
