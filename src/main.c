/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:25:02 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/12 13:21:08 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	t_stack	*temp;
	int		counter;

	counter = 0;
	if (!stack)
		return (0);
	temp = stack;
	while (temp)
	{
		++counter;
		temp = temp->next;
	}
	return (counter);
}

int	push_swap(t_stack **stack_a)
{
	t_info	info;

	if (!(*stack_a))
		return (1);
	initialise_info(&info, stack_a);
	sort_stack(&info);
	*stack_a = info.stack[A];
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	***parsed_args;

	if (argc < 2)
		return (0);
	parsed_args = parse_args(argc, argv);
	if (!parsed_args)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = fill_stack(parsed_args, 1);
	if (!stack_a)
	{
		ft_free(&parsed_args, 3);
		write(2, "Error\n", 6);
		return (2);
	}
	ft_free(&parsed_args, 3);
	push_swap(&stack_a);
	destroy_stack(&stack_a);
	return (0);
}
