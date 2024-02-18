/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:45:23 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 14:50:52 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a(t_stack **stacka)
{
	t_stack	*first;
	t_stack	*temp;

	if (!(*stacka) || !((*stacka)->next))
		return ;
	first = *stacka;
	*stacka = (*stacka)->next;
	temp = *stacka;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	return ;
}

void	rotate_stack_b(t_stack **stackb)
{
	t_stack	*first;
	t_stack	*temp;

	if (!(*stackb) || !((*stackb)->next))
		return ;
	first = *stackb;
	*stackb = (*stackb)->next;
	temp = *stackb;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	return ;
}

void	rotate_both_stacks(t_stack **stacka, t_stack **stackb)
{
	rotate_stack_a(stacka);
	rotate_stack_b(stackb);
	return ;
}
