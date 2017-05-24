from pylab import *
from numpy import *
from gaussquad import *
from hermitepoly import *
from qhowf import *

def neg_f(n,z):
    return pos_f(n,-z)

def pos_f(n,z):
    return tan(z)**2*psi(n,tan(z))**2/cos(z)**2

for k in range(0,4):
    x = linspace(-4,4,100)
    plot(x,H(k,x))
    xlim(-4.0,4.0)

show()

y = linspace(-10,10,100)
plot(y,H(30,y))
show()

N = 100
n = 5
neg_a = -pi/2
neg_b = 0.0
pos_a = neg_b
pos_b = -neg_a

neg_x,neg_w = gaussxwab(N,neg_a,neg_b)

neg_total = 0.0
for i in range(1,N):
    neg_total += neg_w[i]*neg_f(n,neg_x[i])

pos_x,pos_w = gaussxwab(N,pos_a,pos_b)
    
pos_total = 0.0
for i in range(1,N):
    pos_total += pos_w[i]*pos_f(n,pos_x[i])

RMS = sqrt(pos_total+neg_total)
print RMS
