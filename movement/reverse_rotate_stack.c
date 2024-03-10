/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:10:32 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/09 13:30:30 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*temp;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	last = *stack_a;
	temp = NULL;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	reverse_rotate_stack_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*temp;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	last = *stack_b;
	temp = NULL;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_both_stacks(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_stack_a(stack_a);
	reverse_rotate_stack_b(stack_b);
}
