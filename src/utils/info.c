/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:06:07 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/11 13:34:48 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_info(t_info *info, t_stack **stack_a)
{
	info->stack[A] = *stack_a;
	info->stack[B] = NULL;
	info->size_stack[A] = stack_len(*stack_a);
	info->size_stack[B] = 0;
	info->max_stack[A] = MIN_INT;
	info->max_stack[B] = MIN_INT;
	info->min_stack[A] = MAX_INT;
	info->min_stack[B] = MAX_INT;
	info->movements = NULL;
}