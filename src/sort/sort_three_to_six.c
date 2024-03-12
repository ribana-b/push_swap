/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_to_six.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:24:30 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/12 19:46:35 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *info)
{
	if (is_sorted(info->stack[A], 0, info->size_stack[A]))
		return ;
	if (info->stack[A]->value > info->stack[A]->next->value
		&& info->stack[A]->value > info->stack[A]->next->next->value)
		rotate_stack_a(info, true);
	else if (info->stack[A]->value < info->stack[A]->next->value)
		reverse_rotate_stack_a(info, true);
	if (!is_sorted(info->stack[A], 0, info->size_stack[A]))
		swap_stack_a(info, true);
}

void	fill_min_max(t_info *info)
{
	t_stack	*temp;

	temp = info->stack[A];
	while (temp)
	{
		if (temp->value > info->max_stack[A][VALUE])
		{
			info->max_stack[A][VALUE] = temp->value;
			info->max_stack[A][INDEX] = temp->index;
		}
		if (temp->value < info->min_stack[A][VALUE])
		{
			info->min_stack[A][VALUE] = temp->value;
			info->min_stack[A][INDEX] = temp->index;
		}
		temp = temp->next;
	}
}

void	move_min_to_the_top(t_info *info)
{
	size_t	counter;
	t_stack	*temp;

	counter = 0;
	temp = info->stack[A];
	while (temp->value != info->min_stack[A][VALUE])
	{
		temp = temp->next;
		++counter;
	}
	if (counter > info->size_stack[A] / 2)
		while (counter-- - info->size_stack[A] / 2)
			reverse_rotate_stack_a(info, true);
	else
		while (counter--)
			rotate_stack_a(info, true);
}

void	sort_four(t_info *info)
{
	fill_min_max(info);
	move_min_to_the_top(info);
	if (is_sorted(info->stack[A], 0, info->size_stack[A]))
		return ;
	push_to_stack_b(info, true);
	sort_three(info);
	push_to_stack_a(info, true);
}

void	sort_stack(t_info *info)
{
	if (!(info->stack[A])
		|| is_sorted(info->stack[A], 0, info->size_stack[A]))
		return ;
	if (stack_len(info->stack[A]) == 2)
		swap_stack_a(info, true);
	else if (stack_len(info->stack[A]) == 3)
		sort_three(info);
	else if (stack_len(info->stack[A]) == 4)
		sort_four(info);
}
