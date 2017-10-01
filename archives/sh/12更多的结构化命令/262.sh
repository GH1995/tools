#!/bin/bash 
for v in 1 2 3 4 5 6 7 8 9 10
do
    if [ $v -eq 5 ]
    then
        break
    fi

    echo "Iteration number:$v"
done

echo "completed!"
