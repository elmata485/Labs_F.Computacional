#!/usr/bin/env python3

n=0
j=0
suma=0
i=1
while n<10 and j<10:

    suma+=n+j
    n=3*i

    j=5*i
    i+=1
print(suma)


