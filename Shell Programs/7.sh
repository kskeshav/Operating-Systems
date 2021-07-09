#program number: 7
#Student Name: Keshav Singhal; Register Number: IMT2018511
#Date: 10/01/2021
#Description: A shell program that offers the user choice of copying, removing, rename and asks user for the necessary information, such as the file name, new name. 

#! /bin/sh

while true
do
echo " **MENU** "

echo "	1. List of files.
	2. Copying files.
	3. Removing files.
	4. Renaming files."

echo 	"enter your choice "
read choice
case "$choice" in

1 ) echo "The list of file names."
ls -l || echo "These are file";;

2 ) echo "Enter the old filename:"
read ofile
echo "Enter the new file name:"
read nfile
cp $ofile $nfile && echo "Copied sucessfully." || echo "Copied is not possible." ;;

3 )	echo "Enter the file name to remove:"
	read rfile
	rm -f $rfile && echo "Successfully removed." ;;

4 )	echo "Enter the old file name:"
	read ofile
	echo "Enter the new file name:"
	read nfile
	mv $ofile $nfile && echo "The file $ofile name renamed to $nfile." || echo "You can't Rename the file." ;;

* )
	echo "Invalid option."
	echo "Enter correct choice."
esac
done