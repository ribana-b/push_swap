/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:38:22 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/12 08:57:58 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_index_plus_plus(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp)
	{
		++temp->index;
		temp = temp->next;
	}
}

static void	push_index_minus_minus(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp)
	{
		--temp->index;
		temp = temp->next;
	}
}

void	push_to_stack_a(t_stack **stack_a, t_stack **stack_b, t_bool flag)
{
	t_stack	*temp;

	if (!(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	push_index_plus_plus((*stack_a)->next);
	push_index_minus_minus(*stack_b);
	if (flag)
		write(1, "pa\n", 3);
}

void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b, t_bool flag)
{
	t_stack	*temp;

	if (!(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	push_index_plus_plus((*stack_b)->next);
	push_index_minus_minus(*stack_a);
	if (flag)
		write(1, "pb\n", 3);
}
