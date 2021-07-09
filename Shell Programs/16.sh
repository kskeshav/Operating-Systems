#program number: 16
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: a shell script to perform various tasks on input file employee.txt.
#Note file should be in same directory.

#! /bin/sh

awk '{print;}' employee.txt

read -p 'Enter pattern to search: ' pattern
awk "/$pattern/" employee.txt

awk '{print $2,$4;}' employee.txt

awk '
	BEGIN 	{print "Name\tDesignation\tDepartment\tSalary";} 
 			{print $2,"\t",$3,"\t",$4,"\t",$NF;} 
	END 	{print "Report Generated\n--------------"; }
	' employee.txt

awk '$1 >200' employee.txt

awk '$4 ~/Technology/' employee.txt

awk '
	BEGIN { count=0;} 4 ~ /Technology/ { count++; } 
	END { print "Number of employees in Technology Dept =",count;}
	' employee.txt 