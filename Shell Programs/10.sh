#program number: 10
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: A script to backup a directory as a file in the home directory.
#Note: first enter folder name and then file name.
#! /bin/sh

{
	tar czf ~/$2.tar.gz ~/$1
} || {
	echo ERROR
}