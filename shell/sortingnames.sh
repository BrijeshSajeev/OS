#!/bin/sh

read -p "Enter number of names >> " n
echo "Enter the names"

if test -f "sample.txt"
then
rm sample.txt
fi

while [ $n -gt 0 ]
do
read s
echo $s | cat>>sample.txt
n=`expr $n - 1`
done

echo "-------------"
sort "sample.txt"