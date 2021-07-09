#program number: 5
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: a script that uses find to look for a file and echo a suitable message if the file is not found.
#Note: checks for file in current directory.
#! /bin/sh

result=`find ./ -name $1 | wc -l`

if [ $result -eq 0 ]; then 
	echo "file is not present."
else
	echo "file is present."
fi
