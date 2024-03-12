#!/bin/bash

path=$(dirname $0)

test_checker() {
	output=$($path/push_swap $1 | $path/checker_linux $1 | xargs printf "%s")
	if [[ $output == "OK" ]]; then
		printf "\033[32mOK\033[0m\n"
	else
		printf "\033[31mKO\033[0m\n"
	fi
}

test_leaks() {
	output=$(valgrind $path/push_swap $1 2>&1)
	echo "$output" | grep -q "no leaks"
	if [[ $? == 0 ]]; then
		printf "\033[32mLEAKS OK\033[0m\n"
	else
		printf "\033[31mLEAKS KO\033[0m\n"
	fi
}

test_full() {
	output=$($path/push_swap $1 | $path/checker_linux $1 | xargs printf "%s")
	if [[ $output == "OK" ]]; then
		printf "$1: \033[32mOK\033[0m "
	else
		printf "$1: \033[31mKO\033[0m "
	fi

	output=$(valgrind $path/push_swap $1 2>&1)
	echo "$output" | grep -q "no leaks"
	if [[ $? == 0 ]]; then
		printf "\033[32mLEAKS OK\033[0m\n"
	else
		printf "\033[31mLEAKS KO\033[0m\n"
	fi
}

make -s -C . 2> /dev/null
make -s -C .. 2> /dev/null

printf "\n\033[1;33mIgnore the following KOs\033[0m"

echo
echo "No arguments"
test_full

echo
echo "No elements"
test_full '""'
test_full '" "'

printf "\n\033[1;33mDon't ignore the following KOs\033[0m"

echo
echo "One element"
test_full 1

echo
echo "Two elements"
test_full "1 2"
test_full "2 1"

echo
echo "Three elements"
test_full "1 2 3"
test_full "1 3 2"
test_full "2 1 3"
test_full "2 3 1"
test_full "3 1 2"
test_full "3 2 1"
