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

#version for faster generation with a big scale
#if [ $(( $(($2 - $1)) / $3 - 1 )) -lt 1 ] ; then
#        INCREMENT=1;
#else
#        INCREMENT=$(( $(($2 - $1)) / $3 - 1 ))
#fi
#NUMBERS=$( seq -f "%.f" $1 $INCREMENT $2 | sort -R | head -n $3 | tr '\n' ' ' )

NUMBERS=$( seq -f "%.f" $1 $2 | sort -R | head -n $3 | tr '\n' ' ' )
#echo $NUMBERS
./push_swap $NUMBERS | ./checker -v $NUMBERS