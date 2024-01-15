/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_to_six.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:24:30 by ribana-b          #+#    #+#             */
/*   Updated: 2024/01/14 22:41:00 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next || !(*stack)->next->next)
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
	return ;
}

void	sort_stack(t_stack **stacka)
{
	if (!(*stacka))
		return ;
	if (stack_len(*stacka) == 2)
		if (!check_sorted(*stacka))
			swap_stack_a(*stacka);
	if (stack_len(*stacka) == 3)
		sort_three(stacka);
	return ;
}
