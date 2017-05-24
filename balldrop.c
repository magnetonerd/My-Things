#include <stdio.h>
#include <math.h>

#define mass 0.145
#define g 9.81
#define diameter 0.0732
#define c 0.22*diameter*diameter
#define b c/mass
//#define velocity(y) (sqrt((g*mass/c)*(1-exp(-2.0*(c/mass)*378.8-y))))

double velocity(double y){
  return sqrt((g/b)*(1.0-exp(-2.0*b*(378.8-y))));
}

int main()
{
  //double mass;
  
  double y,dt,vy;
  double *p_y = &y;
  double K_Energy, P_Energy;

  *p_y = 378.8;
  dt = 0.01;
  
  while(y >= 370.0){
    //*p_y = *p_y - velocity(*p_y)*dt;
    vy = velocity(*p_y);
    K_Energy = (1.0/2.0)*mass*vy*vy;
    printf("Pos is %f vel is %f KE is %f\n", y, velocity(y), K_Energy);
    *p_y = *p_y - velocity(*p_y)*dt;
  }
}
