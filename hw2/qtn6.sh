#!/bin/bash
# hw2 Question #6
# Michael Scales

sum=0

for val in $@;
do
   squareValue=$(($val*$val))
   echo $squareValue
   sum=$(($sum+$squareValue))
done

echo "The sum is: $sum"
