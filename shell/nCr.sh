#!/bin/sh
clear
factorial(){
    n1=$1
    fact=1

    while [ $n1 -gt 0 ]
    do
        fact=`expr $fact \* $n1`
        n1=`expr $n1 - 1`
    done

}

read -p "Enter the value of n >> " n
read -p "Enter the value of r >> " r

factorial $n
numerator=$fact

factorial $r
r_fact=$fact

n_r=`expr $n - $r`

factorial $n_r
nr_fact=$fact

denominator=`expr $r_fact \* $nr_fact`

result=`expr $numerator / $denominator`

echo "The nCr of $n C $r is $result"
