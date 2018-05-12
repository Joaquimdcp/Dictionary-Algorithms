

#!/bin/bash

i="0"

while [ $i -lt 10 ]
do
    echo $i
    echo 1000000 0 0 | ./a.out &
    wait
    echo 7500 | ./main &
    wait
    i=$[$i+1]
done