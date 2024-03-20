/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:24:41 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/20 11:38:07 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_target(t_info *info, size_t *target, int value, int limit)
{
	t_stack	*temp;

	temp = info->stack[A];
	while (temp)
	{
		if (value < temp->value && temp->value < limit)
		{
			limit = temp->value;
			*target = temp->index;
		}
		temp = temp->next;
	}
	if (limit != MAX_INT)
		return ;
	temp = info->stack[A];
	while (temp)
	{
		if (temp->value < limit)
		{
			limit = temp->value;
			*target = temp->index;
		}
		temp = temp->next;
	}
}

void	assign_target(t_info *info)
{
	t_stack	*temp;
	size_t	target;

	temp = info->stack[B];
	target = 0;
	while (temp)
	{
		if (temp->value == MAX_INT)
			target = info->size_stack[A];
		else
			calculate_target(info, &target, temp->value, MAX_INT);
		temp->target = target;
		temp = temp->next;
	}
}

static int	absolute_value(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

t_stack	*calculate_cheapest(t_info *info)
{
	t_stack	*result;
	t_stack	*temp;

	temp = info->stack[B];
	result = temp;
	while (temp)
	{
		if (absolute_value(temp->cost[A]) + absolute_value(temp->cost[B])
			< absolute_value(result->cost[A]) + absolute_value(result->cost[B]))
			result = temp;
		temp = temp->next;
	}
	return (result);
}

void	assign_cost(t_info *info)
{
	t_stack	*temp;

	temp = info->stack[B];
	while (temp)
	{
		temp->cost[B] = temp->index;
		if (temp->index > info->size_stack[B] / 2)
			temp->cost[B] = (info->size_stack[B] - temp->index) * -1;
		temp->cost[A] = temp->target;
		if (temp->target > info->size_stack[A] / 2)
			temp->cost[A] = (info->size_stack[A] - temp->target) * -1;
		temp = temp->next;
	}
}
