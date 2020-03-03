#!/bin/bash
# counts the average of push_swap moves at given scale
# and given repetitions

if [ $# -ne 4 ] ; then
        echo -e "\nUsage:\t$0 START END AMOUNT TIMES\n"
        exit 1
fi
if [ $(($2 - $1 + 1)) -lt $3 ] ; then
        echo -e "\nUsage:\t$0 START END AMOUNT TIMES
        AMOUNT needs to be less than or equal to (END - START + 1).\n"
        exit 1
fi
SUM=0
for (( I=0; I<$4; I++ )) ; do
        NUMBERS=$( seq $1 $2 | sort -R | head -n $3 | tr '\n' ' ' )
        SUM=$(( $SUM + $( ./push_swap $NUMBERS | wc -l ) ))
        echo $NUMBERS >> results
        ./push_swap $NUMBERS | ./checker $NUMBERS >> results
        if [ $(($I % 30)) -eq 0 ] ; then
            echo -ne . $(( $SUM / ((I+1)) ))
        fi
done
AVERAGE=$(( $SUM / $4 ))
echo -e "\nAverage is $AVERAGE"