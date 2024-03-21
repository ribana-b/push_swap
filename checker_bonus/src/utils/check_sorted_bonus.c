/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:24:32 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/21 02:30:08 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(t_stack *stack, size_t start, size_t end)
{
	t_stack	*temp;

	if (!stack)
	{
		write(1, "KO\n", 3);
		return (FALSE);
	}
	temp = stack;
	while (temp->next && start <= end)
	{
		if (temp->value > temp->next->value && temp->index >= start)
		{
			write(1, "KO\n", 3);
			return (FALSE);
		}
		temp = temp->next;
	}
	write(1, "OK\n", 3);
	return (TRUE);
}
