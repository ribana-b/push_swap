/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:48:46 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/07 09:32:45 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int index, int value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->index = index;
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

void	destroy_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!(*stack))
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

static void	fill_stack_aux(t_stack **temp, char ***parsed_args, int *index,
			int *stack_index)
{
	while (parsed_args[index[0]][index[1]])
	{
		(*temp)->next = create_stack((*stack_index)++,
				ft_atoi(parsed_args[index[0]][index[1]]));
		if (!(*temp)->next)
			return ;
		*temp = (*temp)->next;
		index[1]++;
	}
}

t_stack	*fill_stack(char ***parsed_args, int stack_index)
{
	t_stack	*stack;
	t_stack	*temp;
	int		index[2];

	index[0] = 0;
	temp = create_stack(stack_index++, ft_atoi(parsed_args[index[0]][0]));
	if (!temp)
		return (NULL);
	stack = temp;
	while (parsed_args[index[0]])
	{
		if (index[0] == 0)
			index[1] = 1;
		else
			index[1] = 0;
		fill_stack_aux(&temp, parsed_args, index, &stack_index);
		if (!temp)
		{
			destroy_stack(&stack);
			return (NULL);
		}
		index[0]++;
	}
	temp = NULL;
	return (stack);
}
