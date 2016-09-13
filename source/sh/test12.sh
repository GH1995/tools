#!/bin/bash 

count=1
for param in "$*"
do
    echo "\$* parameter #$count = $param"
    count=$[$count+1]
done


count=1
for param in "$@"
do
    echo "\$@ parameter #$count = $param"
    count=$[$count+1]
done
