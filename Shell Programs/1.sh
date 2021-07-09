#program number: 1
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: A script to count the number of block device files in /dev directory.

#! /bin/sh

ans=`ls -Rl /dev | grep ^b | wc -l`
echo $ans