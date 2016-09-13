#!/bin/bash

func1() {
    echo "try to display a non-existent file."
    ls -l badfile
}

echo "test the function:"
func1 
echo "The exit status is:$?"
