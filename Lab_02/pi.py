#!/usr/bin/env python3

n=90000000000

suma=0
w=1/n
for i in range(0,n):

    x=w*(i-0.5)
    suma += 4/(1+(x*x))
pi_aprrox=suma*w
print(pi_aprrox)



