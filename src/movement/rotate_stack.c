/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:45:23 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/20 11:36:18 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a(t_info *info, t_bool flag)
{
	t_stack	*first;
	t_stack	*temp;

	if (!info->stack[A] || !info->stack[A]->next)
		return ;
	first = info->stack[A];
	info->stack[A] = info->stack[A]->next;
	temp = info->stack[A];
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	if (flag)
		write(1, "ra\n", 3);
}

void	rotate_stack_b(t_info *info, t_bool flag)
{
	t_stack	*first;
	t_stack	*temp;

	if (!info->stack[B] || !info->stack[B]->next)
		return ;
	first = info->stack[B];
	info->stack[B] = info->stack[B]->next;
	temp = info->stack[B];
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	if (flag)
		write(1, "rb\n", 3);
}

void	rotate_both_stacks(t_info *info, t_bool flag)
{
	rotate_stack_a(info, FALSE);
	rotate_stack_b(info, FALSE);
	if (flag)
		write(1, "rr\n", 3);
}
