#!/bin/bash 

read -p "please enter your age: " age
days=$[$age*365]

echo "That makes you over $days old!"
