/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:38:22 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/12 12:13:10 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_a(t_info *info, t_bool flag)
{
	t_stack	*temp;

	if (!info->stack[B])
		return ;
	temp = info->stack[B];
	info->stack[B] = info->stack[B]->next;
	temp->next = info->stack[A];
	info->stack[A] = temp;
	if (flag)
		write(1, "pa\n", 3);
}

void	push_to_stack_b(t_info *info, t_bool flag)
{
	t_stack	*temp;

	if (!info->stack[A])
		return ;
	temp = info->stack[A];
	info->stack[A] = info->stack[A]->next;
	temp->next = info->stack[B];
	info->stack[B] = temp;
	if (flag)
		write(1, "pb\n", 3);
}
