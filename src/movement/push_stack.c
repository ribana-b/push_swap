/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:38:22 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/12 10:10:47 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_index_plus_plus(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp)
	{
		++temp->index;
		temp = temp->next;
	}
}

static void	push_index_minus_minus(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp)
	{
		--temp->index;
		temp = temp->next;
	}
}

void	push_to_stack_a(t_info *info, t_bool flag)
{
	t_stack	*temp;

	if (!info->stack[B])
		return ;
	temp = info->stack[B];
	info->stack[B] = info->stack[B]->next;
	temp->next = info->stack[A];
	info->stack[A] = temp;
	push_index_plus_plus(info->stack[A]->next);
	push_index_minus_minus(info->stack[B]);
	if (flag)
		write(1, "pa\n", 3);
}

void	push_to_stack_b(t_info *info, t_bool flag)
{
	t_stack	*temp;

	if (!info->stack[B])
		return ;
	temp = info->stack[A];
	info->stack[A] = info->stack[A]->next;
	temp->next = info->stack[B];
	info->stack[B] = temp;
	push_index_plus_plus(info->stack[B]->next);
	push_index_minus_minus(info->stack[A]);
	if (flag)
		write(1, "pb\n", 3);
}
