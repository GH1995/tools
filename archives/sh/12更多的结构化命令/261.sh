#!/bin/bash 

IFS.OLD=$IFS
IFS=$'\n'

for e in `cat /etc/passwd`
do
    echo "value in $e - "
    IFS=:
    for v in $e
    do
        echo -n "$v "
    done
    echo \n
done
