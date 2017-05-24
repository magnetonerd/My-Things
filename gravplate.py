from numpy import *
from pylab import *
from gaussquad import *

def f(x,y,z):
    return z*(x**2 + y**2 + z**2)**(-3.0/2.0)

G = 6.674e-11
sigma = 1.0

N = 100
L = 10.0
a = -L/2.0
b = L/2.0

x,wx = gaussxwab(N,a,b)
y,wy = gaussxwab(N,a,b)

total = 0.0
z = linspace(0.0,10.0,100)
for i in range(1,N):
    for j in range(1,N):
        total += wx[i]*wy[j]*f(x[i],y[j],z)

total = G*sigma*total
plot(z,total)
xlim(-1.0,10.0)
show()
