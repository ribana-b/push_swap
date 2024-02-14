/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:10:32 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 02:28:25 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_stack_a(t_stack **stacka)
{
	t_stack	*last;
	t_stack	*temp;

	if (!(*stacka) || !((*stacka)->next))
		return ;
	last = *stacka;
	temp = NULL;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *stacka;
	*stacka = last;
}

void	reverse_rotate_stack_b(t_stack **stackb)
{
	t_stack	*last;
	t_stack	*temp;

	if (!(*stackb) || !((*stackb)->next))
		return ;
	last = *stackb;
	temp = NULL;
	while (last->next)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *stackb;
	*stackb = last;
}

void	reverse_rotate_both_stacks(t_stack **stacka, t_stack **stackb)
{
	reverse_rotate_stack_a(stacka);
	reverse_rotate_stack_b(stackb);
	return ;
}
