#!/bin/bash 
#testing if you can read a file 
# 检查是否可读

pwfile=/etc/shadow 

# first test if the file exists, and is a file.

if [ -f $pwfile ]
then
    # now test if you can read it
    if [ -r $pwfile ]
    then
        tail $pwfile 
    else
        echo "Sorry, I am unable to read the $pwfile."
    fi
else
    echo "Sorry, the file $pwfile does not exists."
fi
