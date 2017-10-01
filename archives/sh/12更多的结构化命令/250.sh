#!/bin/bash

file="states"

IFS=$'\n'
for state in `cat $file`
do
    echo "i: $state"
done
