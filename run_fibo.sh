#!/bin/bash

output_file="results.txt"
> $output_file

for ((n=1; n<=50000; n++))
do
    result=$(python3 fibo.py $n)
    echo $result >> $output_file
done
