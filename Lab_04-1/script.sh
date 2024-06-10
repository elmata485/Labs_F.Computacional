#!/bin/bash


for((i = 1; i <= 16; i++))
do
  
  export OMP_NUM_THREADS=$i

  ./Vector.x >> speedup.dat

done
