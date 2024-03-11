/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_to_six.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:24:30 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/11 13:50:15 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *info)
{
	if (!info->stack[A] || !info->stack[A]->next || !info->stack[A]->next->next
		|| is_sorted(info->stack[A]))
		return ;
	if (info->stack[A]->value > info->stack[A]->next->value
		&& info->stack[A]->value > info->stack[A]->next->next->value)
	{
		rotate_stack_a(&info->stack[A]);
		if (info->stack[A]->value > info->stack[A]->next->value)
			swap_stack_a(info->stack[A]);
	}
	else if (info->stack[A]->value < info->stack[A]->next->value)
	{
		reverse_rotate_stack_a(&info->stack[A]);
		if (info->stack[A]->value > info->stack[A]->next->value)
			swap_stack_a(info->stack[A]);
	}
	else
		swap_stack_a(info->stack[A]);
}

void	sort_stack(t_info *info)
{
	if (!(info->stack[A]) || is_sorted(info->stack[A]))
		return ;
	if (stack_len(info->stack[A]) == 2)
		swap_stack_a(info->stack[A]);
	else if (stack_len(info->stack[A]) == 3)
		sort_three(info);
}
