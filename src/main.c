/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:25:02 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/10 19:37:48 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (!stack)
		return (0);
	temp = stack;
	while (temp)
	{
		++i;
		temp = temp->next;
	}
	return (i);
}

int	push_swap(t_stack **stack_a)
{
	if (!(*stack_a))
		return (1);
	sort_stack(stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	***parsed_args;

	if (argc < 2)
		return (1);
	parsed_args = parse_args(argc, argv);
	if (!parsed_args)
	{
		write(2, "Error\n", 6);
		return (2);
	}
	stack_a = fill_stack(parsed_args, 1);
	if (!stack_a)
	{
		ft_free(&parsed_args, 3);
		write(2, "Error\n", 6);
		return (3);
	}
	ft_free(&parsed_args, 3);
	push_swap(&stack_a);
	destroy_stack(&stack_a);
	return (0);
}
