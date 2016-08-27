#!/bin/bash 

while  getopts :ab:c opt
do
    case "$opt" in
        a) echo "Found the -a option"
            ;;
        b) echo "Found the -b option with value $OPTARG"
            ;;
        c) echo "Found the -c option"
            ;;
        *) echo "Unknow option: $opt"
            ;;
    esac
done
