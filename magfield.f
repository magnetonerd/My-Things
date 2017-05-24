      program Mag

      real*4 m,mu0,I0,R,D,s,L,b,v0
      real*4 pi,K10,K20,k11,k21,vel,I
      integer n,j
!      external k11,k21,vel,I
      pi=acos(-1.0)
      
      m=3.0d-3;mu0=(4.0d-7)*pi;I0=750.0d0;R=10.0d0
      D=3.0d0;L=5.0d-3;s=1.0d-3;v0=20.0d0

      b = mu0*I0/(4*pi)

!      K10 = 1/(s*sqrt(D**2 + s**2)) + 1/((L-s)*sqrt(D**2 + (L-s)**2))
!      K20 = (sqrt(D**2 + s**2)/s)+(sqrt(D**2 + (L-s)**2)/(L-s))-2

      write(*,*) "K10: ", K10
      write(*,*) "K20: ", K20
      
      k10 =  K1(D,s,L)
      k20 =  K2(D,s,L)
      write(*,*) k10,k20
      vel = velocity(b,L,D,m,R,k10,k20,v0)
      I = Current(b,L,D,vel,R,k10)

      end

      function K1(D,s,L)

      real*4 D,s,L,k11

      k11 = 1/(s*sqrt(D**2 + s**2)) + 1/((L-s)*sqrt(D**2 + (L-s)**2))
      write(*,*) "K1: ",k11
      
      return
      end

      function K2(D,s,L)

      real*4 D,s,L,k21

      k21 = (sqrt(D**2 + s**2)/s)+(sqrt(D**2 + (L-s)**2)/(L-s))-2
      write(*,*) "K2: ",k21
      
      return 
      end

      function velocity(b,L,D,m,R,K1,K2,v0)

      real*4 b,L,D,m,R,K1,K2,v0,vel

      vel = -(b**2 * L**2 *D/(m*R))*K1*K2 +v0
      write(*,*) "Velocity: ",vel
      
      return 
      end

      function Current(b,L,D,v,R,K1)

      real*4 b,L,D,R,K1,I

      I = -(b*L*D*v/R)*K1
      write(*,*) "Current: ",I
      
      return
      end 
