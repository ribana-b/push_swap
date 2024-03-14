/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_to_six.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:24:30 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/14 15:43:05 by ribana-b         ###   ########.com      */
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

static void	sort_four(t_info *info)
{
	fill_min_max_index(info, A);
	move_min_to_the_top(info, A);
	if (is_sorted(info->stack[A], 0, info->size_stack[A]))
		return ;
	push_to_stack_b(info, true);
	sort_three(info);
	push_to_stack_a(info, true);
}

static void	sort_five(t_info *info)
{
	fill_min_max_index(info, A);
	move_min_to_the_top(info, A);
	if (is_sorted(info->stack[A], 0, info->size_stack[A]))
		return ;
	push_to_stack_b(info, true);
	reset_info_index(info, A);
	sort_four(info);
	push_to_stack_a(info, true);
}

static void	sort_six(t_info *info)
{
	fill_min_max_index(info, A);
	move_min_to_the_top(info, A);
	if (is_sorted(info->stack[A], 0, info->size_stack[A]))
		return ;
	push_to_stack_b(info, true);
	reset_info_index(info, A);
	sort_five(info);
	push_to_stack_a(info, true);
}

void	sort_two_to_six(t_info *info)
{
	if (!info->stack[A]
		|| is_sorted(info->stack[A], 0, info->size_stack[A]))
		return ;
	if (stack_len(info->stack[A]) == 2)
		swap_stack_a(info, true);
	else if (stack_len(info->stack[A]) == 3)
		sort_three(info);
	else if (stack_len(info->stack[A]) == 4)
		sort_four(info);
	else if (stack_len(info->stack[A]) == 5)
		sort_five(info);
	else
		sort_six(info);
}
