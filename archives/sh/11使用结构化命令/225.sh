#!/bin/bash 
# testing multiple commands in the section
testuser=hxs
if grep $testuser /etc/passwd 
then 
    echo "The bash files for user $testuser are:"
    ls -a /home/$testuser/*
else
    echo "The user name $testuser does not exist on the system."
fi
