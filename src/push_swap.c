/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:25:02 by ribana-b          #+#    #+#             */
/*   Updated: 2024/03/04 15:13:42 by ribana-b         ###   ########.com      */
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
		i++;
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
		ft_putstr_fd("Error\n", 2);
		return (2);
	}
	stack_a = fill_stack(parsed_args, 1);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (3);
	}
	ft_free(&parsed_args, 3);
	push_swap(&stack_a);
	print_stack(stack_a);
	destroy_stack(&stack_a);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack *temp;

// 	if (argc < 2)
// 	{
// 		ft_printf("Usage\n1: %s <list of numbers>\n", argv[0]);
// 		ft_printf("2: %s <n1> <n2> ... <nx>\n", argv[0]);
// 		return (1);
// 	}
// 	int index = 5;
// 	int	arr[6][3] = {{1, 2, 3},
// 					{1, 3, 2},
// 					{2, 1, 3},
// 					{2, 3, 1},
// 					{3, 1, 2},
// 					{3, 2, 1}
// 	};
// 	stack_a = create_stack(0, arr[index][0]);
// 	if (!stack_a)
// 		return (1);
// 	temp = stack_a;
// 	for (int i = 1; i < 3; i++)
// 	{
// 		temp->next = create_stack(i, arr[index][i]);
// 		if (!temp)
// 		{
// 			destroy_stack(&stack_a);
// 			return (1);
// 		}
// 		temp = temp->next;
// 	}
// 	print_stack(stack_a);
// 	push_swap(&stack_a);
// 	print_stack(stack_a);
// 	destroy_stack(&stack_a);
// 	return (0);
// }
