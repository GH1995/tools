#!/bin/bash 
# testing floating point numbers
val1=`echo "scale=4;10/3" | bc`     # test 命令无法处理浮点数
echo "The test value is $val1"
if [ $val1 -gt 3 ]
then 
    echo "The result is larger then 3."
fi
