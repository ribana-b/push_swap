/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:36:26 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/10 18:23:08 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp)
	{
		ft_printf("%d: %d\n", temp->index, temp->value);
		temp = temp->next;
	}
}
