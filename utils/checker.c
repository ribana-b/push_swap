/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:24:32 by ribana-b          #+#    #+#             */
/*   Updated: 2024/03/04 15:11:12 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_reverse_sorted(t_stack *stack)
{
	t_stack	*temp;
	if (!stack)
		return (false);
	temp = stack;
	while (temp->next)
	{
		if (temp->value < temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}

t_bool	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (false);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}
