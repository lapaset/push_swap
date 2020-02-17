#!/bin/bash
# if difference between end and start is more than max_amount
# gives max_amount of integers between start and end values
# in random order divided by spaces.
# else gives all values between end and start in random order
# divided by spaces.
if [ $# -ne 3 ] ; then
        echo -e "\nUsage:\t$0 START END MAX_AMOUNT\n"
        exit 1
fi
seq $1 $2 | sort -R | head -n $3 | tr '\n' ' '
