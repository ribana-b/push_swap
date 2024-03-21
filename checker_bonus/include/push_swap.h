/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:24:52 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/21 02:32:11 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* <-- Defines Section --> */

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define STDIN 0

/* <-- Libraries Section --> */

# include "bfl.h"
# include <unistd.h>
# include <stdlib.h>

/* <-- Typedef Section --> */

typedef enum e_bool			t_bool;
typedef enum e_name			t_name;
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

struct s_stack
{
	int		value;
	size_t	index;
	t_stack	*next;
};

struct s_info
{
	t_stack	*stack[NAME];
	size_t	size_stack[NAME];
};

/* <-- Functions Section --> */

// <-- Stack manipulation --> //

t_stack	*create_stack(int index, int value);
void	destroy_stack(t_stack **stack);
t_stack	*fill_stack(char ***parsed_args, int index);
int		stack_len(t_stack *stack);

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

// <-- Checker --> //

t_bool	is_sorted(t_stack *stack, size_t start, size_t end);

// <-- Parser --> //

char	***parse_args(int argc, char **argv);

// <-- Info --> //

void	reset_info_index(t_info *info, t_name name);
void	initialise_info(t_info *info, t_stack **stack_a);

// <-- Main --> //

void	update_index(t_info *info);

#endif // PUSH_SWAP_H
