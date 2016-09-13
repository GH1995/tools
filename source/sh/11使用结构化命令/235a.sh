#!/bin/bash
#testing if a file is empty

file=t15test
touch file 

if [ -s ${file} ]
then
    echo "The $file exists and has data in it."
else
    echo "The $file exists and is empty."
fi 

date > ${file}

if [ -s ${file} ]
then
    echo "The $file has data in it."
else
    echo "The $file is still empty."
fi

