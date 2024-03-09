/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_to_six.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:24:30 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/08 20:56:39 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next || !(*stack)->next->next
		|| is_sorted(*stack))
		return ;
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
	{
		rotate_stack_a(stack);
		if ((*stack)->value > (*stack)->next->value)
			swap_stack_a(*stack);
	}
	else if ((*stack)->value < (*stack)->next->value)
	{
		reverse_rotate_stack_a(stack);
		if ((*stack)->value > (*stack)->next->value)
			swap_stack_a(*stack);
	}
	else
		swap_stack_a(*stack);
}

void	sort_stack(t_stack **stack_a)
{
	if (!(*stack_a))
		return ;
	else if (stack_len(*stack_a) == 2)
	{
		if (!is_sorted(*stack_a))
			swap_stack_a(*stack_a);
	}
	else if (stack_len(*stack_a) == 3)
		sort_three(stack_a);
}
