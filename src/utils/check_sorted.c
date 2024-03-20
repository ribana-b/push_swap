/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:24:32 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/20 11:35:13 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_reverse_sorted(t_stack *stack, size_t start, size_t end)
{
	t_stack	*temp;

	if (!stack)
		return (FALSE);
	temp = stack;
	while (temp->next && start <= end)
	{
		if (temp->value < temp->next->value
			&& temp->index >= start)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

t_bool	is_sorted(t_stack *stack, size_t start, size_t end)
{
	t_stack	*temp;

	if (!stack)
		return (FALSE);
	temp = stack;
	while (temp->next && start <= end)
	{
		if (temp->value > temp->next->value
			&& temp->index >= start)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}
