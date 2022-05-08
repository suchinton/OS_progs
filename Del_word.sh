#!/bin/bash/
set +x

echo -e "enter the file name: "
read fname
echo -e "enter the word to be deleted: "
read pattern
echo $pattern
sed s/$pattern//g $fname > new_$fname

echo "
The new file (new_$fname) contents are:
"
more new_$fname
