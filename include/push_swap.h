/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:24:52 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/15 11:40:28 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* <-- Defines Section --> */

# define DUMP_LIMIT 1000000

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

void	swap_stack_a(t_stack *stacka);
void	swap_stack_b(t_stack *stackb);
void	swap_both_stacks(t_stack *stacka, t_stack *stackb);
void	push_to_stack_b(t_stack **stacka, t_stack **stackb);
void	push_to_stack_a(t_stack **stacka, t_stack **stackb);
void	rotate_stack_a(t_stack **stacka);
void	rotate_stack_b(t_stack **stackb);
void	rotate_both_stacks(t_stack **stacka, t_stack **stackb);
void	reverse_rotate_stack_a(t_stack **stacka);
void	reverse_rotate_stack_b(t_stack **stacka);
void	reverse_rotate_both_stacks(t_stack **stacka, t_stack **stackb);

// <-- Debug --> //

void	print_stack(t_stack *stack);

// <-- Sort --> //

void	sort_three(t_stack **stack);
void	sort_stack(t_stack **stacka);

// <-- Checker --> //

t_bool	is_sorted(t_stack *stacka);

// <-- Parser --> //

char	***parse_args(int argc, char **argv);

// <-- Main --> //
int		stack_len(t_stack *stack);

#endif
