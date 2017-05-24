program RungeKutta
  implicit none

  integer, parameter::p=8 !specifying number of bites for floats

  double precision function Vin(t)
    real(kind=p)::t
    if(mod(floor(2*t),2).eq.0)then
       Vin = 1
    else
       Vin = -1
    end if
    return
  end function Vin

  double precision function f(x,t)
    double precision x,t,RC,Vin
    RC = 0.5
    f = (Vin(t)-x)/RC
    return
  end function f
  
end program RungeKutta

subroutine rungek(a,b,N,x,p)
  real(kind=p)::h,a,b,x
  real(kind=p)::k1,k2,k3,k4
  real(kind=p), dimension::t(N),xval(N)
  integer::N,i,j
  
  h = (b-a)/N
  
  do i = 1,N
     t(i) = (i-1)*h
  end do
  
  do i  = 1,N
     xval(i) = x
     k1 = h*f(x,t(i))
     k2 = h*f(x+0.5_p*k1,t(i)+0.5_p*h)
     k3 = h*f(x+0.5*_pk2,t(i)+0.5_p*h)
     k4 = h*f(x+k3,t(i)+h)
     x = x + (k1+2*k2+2*k3+k4)/(6._p)
  end do
  
  open(1,file='rkdata.txt')
  
  do i = 1,N
     write(1,*)t(i),xval(i)
  end do
  
end subroutine rungek

