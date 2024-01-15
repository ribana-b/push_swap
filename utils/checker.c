/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:24:32 by ribana-b          #+#    #+#             */
/*   Updated: 2024/01/09 21:24:32 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	check_sorted(t_stack *stacka)
{
	t_stack	*temp;

	if (!stacka)
		return false;
	temp = stacka;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return false;
		temp = temp->next;
	}
	return true;
}
