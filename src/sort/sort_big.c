/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:55:09 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/14 15:42:40 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_best_push(t_info *info)
{
	fill_min_max_index(info, A);
}

void	sort_big(t_info *info)
{
	while (info->size_stack[A] != 3)
		push_to_stack_b(info, true);
	sort_three(info);
	while (info->size_stack[B])
	{
		find_best_push(info);
		reset_info_index(info, A);
	}
}
