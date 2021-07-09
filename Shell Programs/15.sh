#program number: 15
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: a shell script to perform various tasks (input file should be “example”)

#! /bin/sh

filename="example"
read -p 'Enter a pattern: ' pattern
sed -n "/$pattern/p" $filename

read -p 'Enter a pattern: ' pattern 
sed "/$pattern/d" $filename

read -p 'Enter starting pattern: ' pattern1
read -p 'Enter ending pattern: ' pattern2
sed -n "/^$pattern1.*$pattern2$/p" $example $filename

read -p 'Enter line number: ' no
sed -n "$no,$"p $filename

read -p 'Enter pattern1: ' pattern1
read -p 'Enter pattern2: ' pattern2
sed "s/$pattern1/$pattern2/g" $filename

read -p 'Enter string to insert in beginning: ' pattern
sed "s/^/ $pattern /" $filename

read -p 'Enter string to insert at end: ' pattern
sed "s/$/$pattern/" $filename