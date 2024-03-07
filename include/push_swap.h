/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:24:52 by ribana-b          #+#    #+#             */
/*   Updated: 2024/03/07 08:08:52 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* <-- Defines Section --> */

# define DUMP_LIMIT 1000000
# define MAX_INT 2147483647
# define MIN_INT -2147483648

/* <-- Libraries Section --> */

# include "../BFL/include/bfl.h"
# include <stdio.h>
# include <stdlib.h>

/* <-- Typedef Section --> */

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

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

void	sort_three(t_stack **stack);
void	sort_stack(t_stack **stack);

// <-- Checker --> //

t_bool	is_sorted(t_stack *stack);
t_bool	is_reverse_sorted(t_stack *stack);

// <-- Parser --> //

char	***parse_args(int argc, char **argv);

// <-- Main --> //
int		stack_len(t_stack *stack);

#endif
