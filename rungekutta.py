from numpy import *

def Vin(t):
    if (floor(2*t) % 2 == 0):
        V_in = 1
    else:
        V_in = -1
    return V_in

def f(x,t):
    RC = 0.05
    return (Vin(t) - x)/RC

def rungkut(a,b,N,x):

    h = (b-a)/N
    tpoints,xpoints = arange(a,b,h),[]

    for t in tpoints:
        xpoints.append(x)
        k1 = h*f(x,t)
        k2 = h*f(x+0.5*k1,t+0.5*h)
        k3 = h*f(x+0.5*k2,t+0.5*h)
        k4 = h*f(x+k3,t+h)
        x += (k1+2*k2+2*k3+k4)/6

    return tpoints, xpoints
