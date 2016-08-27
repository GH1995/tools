#!/bin/bash
# using the case command

case $USER in 
hxs | rich)
    echo "welcome, $USER.";;
testing)
    echo "echo";;
*)
    echo A;;
esac
