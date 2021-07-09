#program number: 3
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: A shell script that creates a new file associated with each command line argument.

#! /bin/sh

for i in $@
do
	>$i
	echo file created with name $i
done