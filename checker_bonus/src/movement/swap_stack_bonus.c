/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:47:07 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/21 02:30:26 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_a(t_info *info, t_bool flag)
{
	int	temp;

	if (!info->stack[A] || !info->stack[A]->next)
		return ;
	temp = info->stack[A]->value;
	info->stack[A]->value = info->stack[A]->next->value;
	info->stack[A]->next->value = temp;
	if (flag)
		write(1, "sa\n", 3);
}

void	swap_stack_b(t_info *info, t_bool flag)
{
	int	temp;

	if (!info->stack[B] || !info->stack[B]->next)
		return ;
	temp = info->stack[B]->value;
	info->stack[B]->value = info->stack[B]->next->value;
	info->stack[B]->next->value = temp;
	if (flag)
		write(1, "sb\n", 3);
}

void	swap_both_stacks(t_info *info, t_bool flag)
{
	swap_stack_a(info, flag);
	swap_stack_b(info, flag);
}
