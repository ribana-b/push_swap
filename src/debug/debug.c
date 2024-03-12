/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:36:26 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/12 19:57:41 by ribana-b         ###   ########.com      */
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

void	print_info(t_info info)
{
	if (info.size_stack[A])
	{
		ft_printf("max A: %d, in %d\n", info.max_stack[A][VALUE],
			info.max_stack[A][INDEX]);
		ft_printf("min A: %d, in %d\n", info.min_stack[A][VALUE],
			info.min_stack[A][INDEX]);
		ft_printf("size A: %d\n", info.size_stack[A]);
	}
	if (info.size_stack[B])
	{
		ft_printf("size B: %d\n", info.size_stack[B]);
		ft_printf("max B: %d, in %d\n", info.max_stack[B][VALUE],
			info.max_stack[B][INDEX]);
		ft_printf("min B: %d, in %d\n", info.min_stack[B][VALUE],
			info.max_stack[B][INDEX]);
	}
}
