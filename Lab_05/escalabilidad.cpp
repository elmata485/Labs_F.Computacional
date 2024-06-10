#!/bin/bash

export OMP_NUM_THREADS=1
./Matmult.x --l 1450 --m 1450 --n 1450 >> speedup.dat

for((i = 2; i <= 16; i =i+2))
do
  
  export OMP_NUM_THREADS=$i

  ./Matmult.x --l 1450 --m 1450 --n 1450 >> speedup.dat
done 

