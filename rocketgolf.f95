program Golf
  implicit none

  double precision::Up,Tp,v,theta,T,uxval,uyval,u,phi
  double precision, parameter:: pi = acos(-1.0)
  double precision::gamma,Ux,Uy

  Up = 1.0d0/sqrt(3.0)
  Tp = 2.6d7
  v = 0.5d0
  theta = 30.0d0*pi/180.0d0
  !CALL THE GAMMA FUNCTION
  T = gamma(Up)*Tp

  uxval = Ux(Up,theta,v)
  uyval = Uy(Up, theta, v)

  u = sqrt(uxval**2 + uyval**2)
  phi = atan2(uyval,uxval)

  write(*,*)'T= ',T
  write(*,*)'ux= ',uxval
  write(*,*)'uy= ',uyval
  write(*,*)'u= ',u
  write(*,*)'phi= ',phi

  call plotGamma
end program Golf

double precision function gamma(v)
  implicit none

  double precision::v
  gamma = sqrt(1.0d0-v**2)
end function gamma

double precision function Ux(Up, theta, v)
  implicit none

  double precision::Up,theta,v,Upx
  Upx = Up*cos(theta)
  Ux = (Upx + v)/(1.0d0 + v*Upx)
end function Ux

double precision function Uy(Up,theta,v)
  implicit none

  double precision::Up,theta,v,Upx,Upy
  double precision::gamma

  Upx = Up*cos(theta)
  Upy = Up*sin(theta)
  Uy = Upy/(gamma(v)*(1.0d0+v*Upx))
end function Uy

subroutine plotGamma
  use dislin
  implicit none

  integer, parameter::n=1000
  integer::i
  real, dimension(n)::xv,yg
  real::v,gamma

  v = 0.0

  do i = 1,n
     xv(i) = v
     yg(i) = gamma(v)
     v = v + 0.001
  end do

  call metafl('XWIN')
  call disini
  call titlin('gamma(v) vs. v',1)
  call name('v','X')
  call name('gamma(v)','Y')
  call graf(-0.5,1.05,0.,.1,-1.,26.,0.,5.)
  call grid(1,1)
  call title
  call color('RED')
  call curve(xv,yg,n)
  call disfin
end subroutine plotGamma

