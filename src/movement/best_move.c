/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:59:15 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/20 11:36:35 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_the_top(t_info *info, t_name name)
{
	size_t	counter;
	t_stack	*temp;

	counter = 0;
	temp = info->stack[name];
	while (temp && temp->value != info->min_stack[name][VALUE])
	{
		temp = temp->next;
		++counter;
	}
	if (counter > info->size_stack[name] / 2 && name == A)
		while (info->size_stack[name] - counter++)
			reverse_rotate_stack_a(info, TRUE);
	else if (counter <= info->size_stack[name] / 2 && name == A)
		while (counter--)
			rotate_stack_a(info, TRUE);
	else if (counter > info->size_stack[name] / 2 && name == B)
		while (info->size_stack[name] - counter++)
			reverse_rotate_stack_b(info, TRUE);
	else
		while (counter--)
			rotate_stack_b(info, TRUE);
}

void	move_max_to_the_top(t_info *info, t_name name)
{
	size_t	counter;
	t_stack	*temp;

	counter = 0;
	temp = info->stack[name];
	while (temp && temp->value != info->max_stack[name][VALUE])
	{
		temp = temp->next;
		++counter;
	}
	if (counter > info->size_stack[name] / 2 && name == A)
		while (info->size_stack[name] - counter++)
			reverse_rotate_stack_a(info, TRUE);
	else if (counter <= info->size_stack[name] / 2 && name == A)
		while (counter--)
			rotate_stack_a(info, TRUE);
	else if (counter > info->size_stack[name] / 2 && name == B)
		while (info->size_stack[name] - counter++)
			reverse_rotate_stack_b(info, TRUE);
	else
		while (counter--)
			rotate_stack_b(info, TRUE);
}

void	apply_movement(t_info *info, t_stack *cheap)
{
	if (cheap->cost[A] == 0 && cheap->cost[B] == 0)
		push_to_stack_a(info, TRUE);
	else if (cheap->cost[A] < 0 && cheap->cost[B] < 0)
		reverse_rotate_both_stacks(info, TRUE);
	else if (cheap->cost[A] > 0 && cheap->cost[B] > 0)
		rotate_both_stacks(info, TRUE);
	else if (cheap->cost[A] < 0)
		reverse_rotate_stack_a(info, TRUE);
	else if (cheap->cost[A] > 0)
		rotate_stack_a(info, TRUE);
	else if (cheap->cost[B] < 0)
		reverse_rotate_stack_b(info, TRUE);
	else if (cheap->cost[B] > 0)
		rotate_stack_b(info, TRUE);
}
