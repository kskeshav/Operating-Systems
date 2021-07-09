#program number: 2
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description:  	A shell program that checks the number of command line arguments 
#				and echoes an error message if there are not exactly three arguments 
#				or echoes the arguments themselves if there are three.

#! /bin/sh

if [ $# != 3 ]; then
	echo "error! less than 3 arguments!" 
else
	echo $@
fi