#program number: 14
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: a shell script to print, “Good Morning/Afternoon/Evening based on the current system time.

#! /bin/sh

h=`date +%H`

if [ $h -lt 12 ]; then
	echo "Good morning"
elif [ $h -lt 18 ]; then
	echo "Good afternoon"
else
	echo "Good evening"
fi