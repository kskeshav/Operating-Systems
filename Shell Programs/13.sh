#program number: 13
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: a shell script to print a multiplication table.

#! /bin/sh

read -p 'Enter a Number: ' n
i=1
while [ $i -le 10 ]
do
	echo " $n x $i = `expr $n \* $i`"
	i=`expr $i + 1`
done