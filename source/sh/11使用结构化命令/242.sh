#!/bin/bash 
# using pattern matching

if [[ $USER == r* ]]
then 
    echo "Hello, $USER."
else
    echo 'sorry, I dont know you.'
fi
