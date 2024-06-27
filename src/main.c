/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:25:02 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/06/27 08:56:49 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_swap(t_stack **stack_a)
{
	t_info	info;

	initialise_info(&info, stack_a);
	sort_number(&info);
	*stack_a = info.stack[A];
	return (0);
}

size_t	ft_numlen(const char *str)
{
	size_t	counter;
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	counter = 0;
	while (str[index] && str[index + 1] && str[index] == '0')
		++index;
	while (str[index])
	{
		++counter;
		++index;
	}
	return (counter);
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
