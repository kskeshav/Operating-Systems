#program number: 9
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: A shell script that accepts a file name starting and ending line numbers as arguments and displays all the lines between the given line numbers. 

#! /bin/sh

echo "filename: $1"
echo "starting line number: $2"
echo "ending line number: $3"
sed -n $2,$3\p $1