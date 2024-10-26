#!/bin/bash

output_file="results.txt"
> $output_file

for ((n=1; n<=50000; n++))
do
    result=$(./fibo "$n")
    echo $result >> $output_file
done
