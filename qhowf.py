from numpy import *
from math import factorial
from hermitepoly import *

def psi(n,x):
    const = 1/sqrt(2**n*factorial(n)*sqrt(pi))
    return const*exp(-(x**2/2))*H(n,x)
