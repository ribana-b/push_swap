/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:24:30 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/20 12:47:31 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_info *info)
{
	if (is_sorted(info->stack[A], 0, info->size_stack[A]))
		return ;
	if (info->stack[A]->value > info->stack[A]->next->value
		&& info->stack[A]->value > info->stack[A]->next->next->value)
		rotate_stack_a(info, TRUE);
	else if (info->stack[A]->value < info->stack[A]->next->value)
		reverse_rotate_stack_a(info, TRUE);
	if (!is_sorted(info->stack[A], 0, info->size_stack[A]))
		swap_stack_a(info, TRUE);
}

static void	sort_fast(t_info *info)
{
	while (info->size_stack[A] > 3)
	{
		fill_min_max_index(info, A);
		move_min_to_the_top(info, A);
		if (is_sorted(info->stack[A], 0, info->size_stack[A]))
			break ;
		push_to_stack_b(info, TRUE);
		reset_info_index(info, A);
	}
	sort_three(info);
	reset_info_index(info, A);
	while (info->size_stack[B])
		push_to_stack_a(info, TRUE);
	move_min_to_the_top(info, A);
}

static int	calculate_average(t_info *info)
{
	int		sum;
	t_stack	*temp;

	sum = 0;
	temp = info->stack[A];
	while (temp)
	{
		sum += temp->value;
		temp = temp->next;
	}
	return (sum / (int)info->size_stack[A]);
}

static void	sort_cost(t_info *info)
{
	t_stack	*cheap;

	while (info->size_stack[A] > 3)
	{
		if (info->stack[A]->value < calculate_average(info))
			push_to_stack_b(info, TRUE);
		else
			rotate_stack_a(info, TRUE);
		if (is_sorted(info->stack[A], 0, info->size_stack[A]))
			break ;
	}
	sort_three(info);
	while (info->size_stack[B])
	{
		update_index(info);
		assign_target(info);
		assign_cost(info);
		cheap = calculate_cheapest(info);
		apply_movement(info, cheap);
	}
	update_index(info);
	fill_min_max_index(info, A);
	move_min_to_the_top(info, A);
}

void	sort_number(t_info *info)
{
	if (!info->stack[A]
		|| is_sorted(info->stack[A], 0, info->size_stack[A]))
		return ;
	if (info->size_stack[A] == 2)
		swap_stack_a(info, TRUE);
	else if (info->size_stack[A] == 3)
		sort_three(info);
	else if (info->size_stack[A] <= 10)
		sort_fast(info);
	else
		sort_cost(info);
}
