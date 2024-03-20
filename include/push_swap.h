/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:24:52 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/20 11:47:27 by ribana-b         ###   ########.com      */
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
typedef enum e_name			t_name;
typedef enum e_element		t_element;
typedef struct s_info		t_info;
typedef struct s_stack		t_stack;
typedef struct s_movement	t_movement;

enum e_bool
{
	FALSE,
	TRUE
};

enum e_name
{
	A,
	B,
	NAME
};

enum e_element
{
	INDEX,
	VALUE,
	ELEMENT
};

struct s_stack
{
	int		value;
	size_t	index;
	size_t	target;
	int		cost[NAME];
	t_stack	*next;
};

struct s_info
{
	t_stack	*stack[NAME];
	size_t	size_stack[NAME];
	int		max_stack[NAME][ELEMENT];
	int		min_stack[NAME][ELEMENT];
};

/* <-- Functions Section --> */

// <-- Stack manipulation --> //

t_stack	*create_stack(int index, int value);
void	destroy_stack(t_stack **stack);
t_stack	*fill_stack(char ***parsed_args, int index);

// <-- Movements --> //

void	push_to_stack_a(t_info *info, t_bool flag);
void	push_to_stack_b(t_info *info, t_bool flag);
void	swap_stack_a(t_info *info, t_bool flag);
void	swap_stack_b(t_info *info, t_bool flag);
void	swap_both_stacks(t_info *info, t_bool flag);
void	rotate_stack_a(t_info *info, t_bool flag);
void	rotate_stack_b(t_info *info, t_bool flag);
void	rotate_both_stacks(t_info *info, t_bool flag);
void	reverse_rotate_stack_a(t_info *info, t_bool flag);
void	reverse_rotate_stack_b(t_info *info, t_bool flag);
void	reverse_rotate_both_stacks(t_info *info, t_bool flag);
void	move_min_to_the_top(t_info *info, t_name name);
void	move_max_to_the_top(t_info *info, t_name name);
void	apply_movement(t_info *info, t_stack *cheap);

// <-- Sort --> //

void	sort_number(t_info *info);
t_stack	*calculate_cheapest(t_info *info);
void	assign_cost(t_info *info);
void	assign_target(t_info *info);

// <-- Checker --> //

t_bool	is_sorted(t_stack *stack, size_t start, size_t end);
t_bool	is_reverse_sorted(t_stack *stack, size_t start, size_t end);

// <-- Parser --> //

char	***parse_args(int argc, char **argv);

// <-- Info --> //

void	fill_min_max_index(t_info *info, t_name name);
void	reset_info_index(t_info *info, t_name name);
void	initialise_info(t_info *info, t_stack **stack_a);

// <-- Main --> //
int		stack_len(t_stack *stack);
void	update_index(t_info *info);

#endif // PUSH_SWAP_H
