#program number: 11
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: A script to check how much space is used by each directory of a given file system.

#! /bin/sh

space=`du -h ~/$1`
echo $space