/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:25:02 by ribana-b          #+#    #+#             */
/*   Updated: 2024/01/14 23:31:07 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_len(t_stack *stack)
{
	t_stack	*temp;
	int i = 0;

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

int	push_swap(char **argv)
{
	t_stack	*stacka;

	if (fill_stacka(&stacka, argv) < 0)
		return (-1);
	if (stacka || check_sorted(stacka))
		return (1);
	sort_stack(&stacka);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Usage\n1: %s <list of numbers>\n", argv[0]);
		ft_printf("2: %s <n1> <n2> ... <nx>\n", argv[0]);
		return (1);
	}
	if (argc == 2)
		argv = ft_split(argv + 1, ' ');
	if (push_swap(argv) < 0)
	{
		// Free function
	}
}

// int	main(int argc, char **argv)
// {
// 	t_stack	*stacka;
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
// 	stacka = create_stack(0, arr[index][0]);
// 	if (!stacka)
// 		return (1);
// 	temp = stacka;
// 	for (int i = 1; i < 3; i++)
// 	{
// 		temp->next = create_stack(i, arr[index][i]);
// 		if (!temp)
// 		{
// 			destroy_stack(&stacka);
// 			return (1);
// 		}
// 		temp = temp->next;
// 	}
// 	print_stack(stacka);
// 	push_swap(&stacka);
// 	print_stack(stacka);
// 	destroy_stack(&stacka);
// 	return (0);
// }
