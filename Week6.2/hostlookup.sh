#!/bin/bash
#comments go here!
#Hi this is a comment

if [ $# -eq 0 ]; then 
echo "No arguments supplied"
exit 1
fi

if [ ! -f $1 ]; then
echo "File Does not exist"
exit 1
fi

while read line;
do
 host -W1 -t A $line
done < $1

exit 0
