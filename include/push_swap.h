/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:24:52 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/11 13:23:34 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* <-- Defines Section --> */

# define MAX_INT 2147483647
# define MIN_INT -2147483648

/* <-- Libraries Section --> */

# include "bfl.h"

/* <-- Typedef Section --> */

typedef enum e_bool			t_bool;
typedef enum e_index		t_index;
typedef struct s_info		t_info;
typedef struct s_stack		t_stack;
typedef struct s_movement	t_movement;

enum e_bool
{
	false,
	true
};

enum e_index
{
	A,
	B,
	AMOUNT
};

struct s_stack
{
	int		value;
	int		index;
	t_stack	*next;
};

struct s_info
{
	t_stack	*stack[AMOUNT];
	size_t	size_stack[AMOUNT];
	int		max_stack[AMOUNT];
	int		min_stack[AMOUNT];
	int		mid_stack[AMOUNT];
	char	*movements;
};

/* <-- Functions Section --> */

// <-- Stack manipulation -->//

t_stack	*create_stack(int index, int value);
void	destroy_stack(t_stack **stack);
t_stack	*fill_stack(char ***parsed_args, int index);

// <-- Movements --> //

void	swap_stack_a(t_stack *stack_a);
void	swap_stack_b(t_stack *stack_b);
void	swap_both_stacks(t_stack *stack_a, t_stack *stack_b);
void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b);
void	push_to_stack_a(t_stack **stack_a, t_stack **stack_b);
void	rotate_stack_a(t_stack **stack_a);
void	rotate_stack_b(t_stack **stack_b);
void	rotate_both_stacks(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_stack_a(t_stack **stack_a);
void	reverse_rotate_stack_b(t_stack **stack_a);
void	reverse_rotate_both_stacks(t_stack **stack_a, t_stack **stack_b);

// <-- Debug --> //

void	print_stack(t_stack *stack);

// <-- Sort --> //

void	sort_three(t_info *info);
void	sort_stack(t_info *info);

// <-- Checker --> //

t_bool	is_sorted(t_stack *stack);
t_bool	is_reverse_sorted(t_stack *stack);

// <-- Parser --> //

char	***parse_args(int argc, char **argv);

// <-- Info --> //

void	initialise_info(t_info *info, t_stack **stack_a);

// <-- Main --> //
int		stack_len(t_stack *stack);

#endif
