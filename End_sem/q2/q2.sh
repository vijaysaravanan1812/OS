stu="student.txt"
exit=0
while [ $exit -ne 1 ]
do
echo "What operation do you want?"
echo -e "add, count no. of student, display, find student with O grade, exit: "
read answer
if [ "$answer" = "add" ]
then
echo -n "Name of person: "
read name
echo -n "number: "
read num
echo -n "grade: "
read grade
echo -n "mark: "
read mark
echo -n "degree: "
read degree
echo "Should I enter the values:"
echo -e "$name ; $number ; $grade ; $mark ; $degree \n"
echo -n "y/n: "
read answer
if [ "$answer" = "y" ]
then
echo "$name ; $number ; $grade ; $mark ; $degree" >>$stu
else
echo "$name ; $phone NOT written to $BOOK"
fi
elif [ "$answer" = "display" ]
then
cat $stu
elif [ "$answer" = "find" ]
then
find=o
grep -i $find $stu
elif [ "$answer" = "count" ]
then
echo "No. of students is : "
wc -l $stu
elif [ "$answer" = "exit" ]
then
exit=1
else
echo "I do not understand the command."
fi
done
exit=0