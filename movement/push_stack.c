/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:38:22 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 01:55:10 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_index_plus_plus(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp)
	{
		temp->index++;
		temp = temp->next;
	}
	return ;
}

static void	push_index_minus_minus(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp)
	{
		temp->index--;
		temp = temp->next;
	}
	return ;
}

void	push_to_stack_a(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;

	if (!(*stackb))
		return ;
	temp = *stackb;
	*stackb = (*stackb)->next;
	temp->next = *stacka;
	*stacka = temp;
	push_index_plus_plus((*stacka)->next);
	push_index_minus_minus((*stackb));
	return ;
}

void	push_to_stack_b(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;

	if (!(*stacka) || !((*stacka)->next))
		return ;
	temp = *stacka;
	*stacka = (*stacka)->next;
	temp->next = *stackb;
	*stackb = temp;
	push_index_plus_plus((*stackb)->next);
	push_index_minus_minus((*stacka));
	return ;
}
