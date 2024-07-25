# push_swap

## Description

Push_swap is a function that sorts in ascending order a stack (stack a) using a temporal stack (stack b).

### Allowed Operations

- **sa**: Swaps the first two elements at the top of **stack a**.
- **sb**: Swaps the first two elements at the top of **stack b**.
- **ss**: Does **sa** and **sb** at the same time.
- **pa**: If **stack b** is not empty, puts the first element at the top into **stack a**.
- **pb**: If **stack a** is not empty, puts the first element at the top into **stack b**.
- **ra**: Shifts up all elements of **stack a** by 1. So the first element becomes the last one.
- **rb**: Shifts up all elements of **stack b** by 1. So the first element becomes the last one.
- **rr**: Does **ra** and **rb** at the same time.
- **rra**: Shifts down all elements of **stack a** by 1. So the last element becomes the first one.
- **rrb**: Shifts down all elements of **stack b** by 1. So the last element becomes the first one.
- **rrr**: Does **rra** and **rrb** at the same time.

The goal is to sort the stack in the lowest amount of operations possible.

### Usage

Clone and compile the project
```shell
git clone https://github.com/ribana-b/push_swap.git
cd push_swap
make
```

Execute the program
```shell
./bin/push_swap <args>
```

### Examples

```shell
./bin/push_swap 5 3 2
```

```shell
./bin/push_swap "3 1" "5 6" "2 7"
```

```shell
./bin/push_swap "2915" 1258 "98123 -1 -2 -3" 
```

## Bonus

The goal of the bonus is to replicate the behaviour of the given checker for push_swap.

### Usage

Compile the bonus part
```shell
make bonus
```
Alternatively
```shell
cd checker_bonus
make
```

Execute the program
```shell
./checker_bonus/bin/checker <args>
```

Then you have to introduce the movements and press <kbd>Ctrl + D</kbd> when you are finished.

Additionally, you can pipe the output of push_swap
```
./bin/push_swap <args> | ./checker_bonus/bin/checker <args>
```

> [!NOTE]
> `args` must be the same for both `push_swap` and `checker`.

### Examples

```shell
./checker_bonus/bin/checker 5 3 2 << EOF
sa
rra
EOF
```

```
./bin/push_swap 25 30 1 -1 | ./checker_bonus/bin/checker 25 30 1 -1
```

## Allowed Functions

- [write()](https://man7.org/linux/man-pages/man2/write.2.html)
- [read()](https://linux.die.net/man/3/read)
- [malloc()](https://www.man7.org/linux/man-pages/man3/malloc.3.html)
- [free()](https://linux.die.net/man/3/free)
- [exit()](https://linux.die.net/man/3/exit)
- Any function I code from scratch.

## Resources

- Random Number Generator: https://www.random.org/integer-sets/

## Progress

If you want to check my progress as a student in 42 Málaga check out my [main repository](https://github.com/SrVariable/42Malaga)!
