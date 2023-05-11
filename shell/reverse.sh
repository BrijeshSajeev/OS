#!/bin/sh

read -p "Enter a string " str

lenth=`echo "$str" | wc -m`

while [ $lenth -gt 0 ]
do
    char=`echo $str | cut -c $lenth`
    lenth=`expr $lenth - 1`
    rev=${rev}${char}
done
echo $rev