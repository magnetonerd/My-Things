from numpy import *
from pylab import *
from rungekutta import rungkut

a = 0.0
b = 10.0
N = 1000
Vout = 0.0

tval,xval = rungkut(a,b,N,Vout)

plot(tval,xval)
xlabel("t")
ylabel("x(t)")
show()
