#!/bin/bash 
# checking if a directory.

if [ -e $HOME ]
then
    echo "OK on the directory. now to check the file."
    #check if a file exists
    if [ -e $HOME/testing ]
    then
        echo "Appending date to existing file."
        date >> $HOME testing 
    else
        #the file does not exist. create a new file.
        echo "Create new file."
        date > $HOME/github/sh/temp
    fi
else
    echo "Sorry. you do not have a HOME directory."
fi
