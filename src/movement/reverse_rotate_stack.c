/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:10:32 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/20 11:35:57 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack_a(t_info *info, t_bool flag)
{
	t_stack	*last;
	t_stack	*temp;

	if (!info->stack[A] || !info->stack[A]->next)
		return ;
	last = info->stack[A];
	temp = NULL;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = info->stack[A];
	info->stack[A] = last;
	if (flag)
		write(1, "rra\n", 4);
}

void	reverse_rotate_stack_b(t_info *info, t_bool flag)
{
	t_stack	*last;
	t_stack	*temp;

	if (!info->stack[B] || !info->stack[B]->next)
		return ;
	last = info->stack[B];
	temp = NULL;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = info->stack[B];
	info->stack[B] = last;
	if (flag)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_both_stacks(t_info *info, t_bool flag)
{
	reverse_rotate_stack_a(info, FALSE);
	reverse_rotate_stack_b(info, FALSE);
	if (flag)
		write(1, "rrr\n", 4);
}
