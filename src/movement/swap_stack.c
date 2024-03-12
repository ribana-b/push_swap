/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:47:07 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/12 08:54:14 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_a(t_stack *stack_a, t_bool flag)
{
	int	temp;

	if (!stack_a || !stack_a->next)
		return ;
	temp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = temp;
	if (flag)
		write(1, "sa\n", 3);
}

void	swap_stack_b(t_stack *stack_b, t_bool flag)
{
	int	temp;

	if (!stack_b || !stack_b->next)
		return ;
	temp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = temp;
	if (flag)
		write(1, "sb\n", 3);
}

void	swap_both_stacks(t_stack *stack_a, t_stack *stack_b, t_bool flag)
{
	swap_stack_a(stack_a, flag);
	swap_stack_b(stack_b, flag);
}
