for (( I=0; I<$4; I++ )) ; do
        NUMBERS=$( jot -r $3 $1 $2 | tr '\n' ' ' )
        echo $NUMBERS 
done