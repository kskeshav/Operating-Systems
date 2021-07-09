#program number: 8
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: A shell script that takes a login name as command- line argument and reports when that person logged in.

#! /bin/sh

if [ $# -lt 1 ]; then
	echo improper usage
	echo correct usage is: $0 username
	exit
else
	last $1 && echo "these are the details of user $1"
fi