/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:24:52 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 02:30:36 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* <--Defines Section--> */

/* <--Libraries Section--> */

# include <stdio.h>
# include <stdlib.h>

/* <--Structs Section--> */

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* <--Functions Section--> */


// <--Stack manipulation-->//

t_stack	*create_stack(int index, int value);
void	destroy_stack(t_stack **stack);


// <--Movements--> //

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

#endif
