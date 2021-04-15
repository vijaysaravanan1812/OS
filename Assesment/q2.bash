#!/bin/bash
n=5
i=1
while [ $i -le $n ]
do
	echo "Enter register number"
	read r
	echo "Enter marks out of 100"
	read m
	if [ $m -le 100 -a $m -ge 90 ]
	then
		echo "Grade: O"
	elif [ $m -le 89 -a $m -ge 80 ]
	then
		echo "Grade: A+"
	elif [ $m -le 79 -a $m -ge 70 ]
	then
		echo "Grade: A"
	elif [ $m -le 69 -a $m -ge 60 ]
	then
		echo "Grade: B+"
	elif [ $m -le 59 -a $m -ge 50 ]
	then
		echo "Grade: B"
	else
		echo "Grade: F"
	fi
	i=`expr $i + 1`
done