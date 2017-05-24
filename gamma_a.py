from numpy import *
from pylab import *

def z(x,c):
    return x/(c+x)

def f(a,z):
    return z**(a-1)*exp(-z)

x = linspace(0,5,100)

for a in range(2,5):
    plot(x,f(a,x))

show()
