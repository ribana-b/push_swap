#!/bin/bash

# NOTE: ChatGPT generated code because I have skill issue

# Function to generate permutations iteratively
generate_permutations() {
    local input=("$@")
    local length=${#input[@]}
    local indices=($(seq 0 $(($length - 1))))
    local count=0
    
    while true; do
        # Output current permutation
        for i in "${indices[@]}"; do
            echo -n "${input[$i]} "
        done
        echo
        
        # Find the first index to update
        local j=$(($length - 2))
        while [ $j -ge 0 ]; do
            if [ ${indices[$j]} -lt ${indices[$(($j + 1))]} ]; then
                break
            fi
            j=$(($j - 1))
        done
        
        # If no such index found, we're done
        if [ $j -lt 0 ]; then
            break
        fi
        
        # Find the smallest index to the right of j whose value is greater than indices[j]
        local k=$(($length - 1))
        while [ $k -gt $j ]; do
            if [ ${indices[$k]} -gt ${indices[$j]} ]; then
                break
            fi
            k=$(($k - 1))
        done
        
        # Swap indices[j] and indices[k]
        local temp=${indices[$j]}
        indices[$j]=${indices[$k]}
        indices[$k]=$temp
        
        # Reverse the elements to the right of j
        local left=$(($j + 1))
        local right=$(($length - 1))
        while [ $left -lt $right ]; do
            temp=${indices[$left]}
            indices[$left]=${indices[$right]}
            indices[$right]=$temp
            left=$(($left + 1))
            right=$(($right - 1))
        done
        
        count=$(($count + 1))
    done
}

# Example usage
 arg=($@)

# Generate permutations
generate_permutations ${arg[@]}
