#!/bin/bash
# hw2 Question #7
# Michael Scales

if [ $# -ne 1 ]; then
   echo "Too many arguments: '$@'"
   exit 1
fi

if [ ! -d $1 ]; then
   echo "Argument '$1' is not a directory."
   exit 1
fi

files=$(ls -a $1)

for file in $files;
do
   if [ -f $file ] && [ ! -s $file ]; then
      echo "'$file' is a zero length file."
   fi
done
