/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:59:15 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/13 09:00:13 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_the_top(t_info *info)
{
	size_t	counter;
	t_stack	*temp;

	counter = 0;
	temp = info->stack[A];
	while (temp && temp->value != info->min_stack[A][VALUE])
	{
		temp = temp->next;
		++counter;
	}
	if (counter > info->size_stack[A] / 2)
		while (info->size_stack[A] - counter++)
			reverse_rotate_stack_a(info, true);
	else
		while (counter--)
			rotate_stack_a(info, true);
}
