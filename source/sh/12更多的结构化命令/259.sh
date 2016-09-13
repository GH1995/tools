#!/bin/bash

for ((a = 1; a <= 3; a++))
do
    echo "A::$a"
    for ((b = 1; b <= 3; b++))
    do
        echo "B::$b"
    done
done
