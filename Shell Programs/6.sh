#program number: 6
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description:  A script which will give 4 choices to the user 1. ls   2. pwd  3. who 4. exit and execute the command as per the users choice.

#! /bin/sh

read -p "1.ls 2.pwd 3.who 4.exit: " choice
if [ $choice = 1 ]; then
	ls
elif [ $choice = 2 ]; then
	pwd
elif [ $choice = 3 ]; then
	who
elif [ $choice = 4 ]; then
	exit
else
	echo "wrong choice"
fi