/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:47:07 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 14:50:48 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_a(t_stack *stacka)
{
	int	temp;

	if (!stacka || !stacka->next)
		return ;
	temp = stacka->value;
	stacka->value = stacka->next->value;
	stacka->next->value = temp;
	return ;
}

void	swap_stack_b(t_stack *stackb)
{
	int	temp;

	if (!stackb || !stackb->next)
		return ;
	temp = stackb->value;
	stackb->value = stackb->next->value;
	stackb->next->value = temp;
	return ;
}

void	swap_both_stacks(t_stack *stacka, t_stack *stackb)
{
	swap_stack_a(stacka);
	swap_stack_b(stackb);
	return ;
}
