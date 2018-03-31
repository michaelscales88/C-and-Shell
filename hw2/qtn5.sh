#!/bin/bash
# hw2 Question #5
# Michael Scales

gcc -o foo foo.c

if [ $? -ne 0 ]; then
   echo "The C code cannot be compiled."
   exit 1
fi

./foo

if [ $? -ne 0 ]; then
   echo "The C program cannot be executed."
   exit 1
fi
