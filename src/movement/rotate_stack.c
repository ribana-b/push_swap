/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:45:23 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/12 08:57:37 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a(t_stack **stack_a, t_bool flag)
{
	t_stack	*first;
	t_stack	*temp;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	if (flag)
		write(1, "ra\n", 3);
}

void	rotate_stack_b(t_stack **stack_b, t_bool flag)
{
	t_stack	*first;
	t_stack	*temp;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	temp = *stack_b;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	if (flag)
		write(1, "rb\n", 3);
}

void	rotate_both_stacks(t_stack **stack_a, t_stack **stack_b, t_bool flag)
{
	rotate_stack_a(stack_a, flag);
	rotate_stack_b(stack_b, flag);
}
