def H(n,x):
    H0 = 1
    H1 = 2*x
    for k in range(1,n):
        H0,H1 = H1,2*x*H1-2*k*H0

    return H1
