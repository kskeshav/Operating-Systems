#program number: 12
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: A script that gives output based on search input.

#! /bin/sh

read -p "search: " tag
if [ "$tag" = "IIT" ]; then
	echo 'NIT'
elif [ "$tag" = "NIT" ]; then
	echo 'IIT'
else
	echo STDERR
fi