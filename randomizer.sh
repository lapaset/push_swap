#!/bin/bash
# if difference between end and start is more than max_amount
# NUMBERS is max_amount of integers between start and end values
# in random order divided by spaces.
# else NUMBERS is all values between end and start in random order
# divided by spaces.
# runs push_swap and checker with NUMBERS.
if [ $# -ne 3 ] ; then
        echo -e "\nUsage:\t$0 START END MAX_AMOUNT\n"
        exit 1
fi
NUMBERS=$( seq $1 $2 | sort -R | head -n $3 | tr '\n' ' ' )
./push_swap $NUMBERS | ./checker -v -d $NUMBERS
#./push_swap $NUMBERS
#echo $NUMBERS