/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:25:02 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/21 02:50:03 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	apply_movement(t_info *info, char *movement)
{
	if (ft_strncmp(movement, "pa\n", 3) == 0)
		push_to_stack_a(info, FALSE);
	else if (ft_strncmp(movement, "pb\n", 3) == 0)
		push_to_stack_b(info, FALSE);
	else if (ft_strncmp(movement, "sa\n", 3) == 0)
		swap_stack_a(info, FALSE);
	else if (ft_strncmp(movement, "sb\n", 3) == 0)
		swap_stack_b(info, FALSE);
	else if (ft_strncmp(movement, "ra\n", 3) == 0)
		rotate_stack_a(info, FALSE);
	else if (ft_strncmp(movement, "rb\n", 3) == 0)
		rotate_stack_b(info, FALSE);
	else if (ft_strncmp(movement, "rr\n", 3) == 0)
		rotate_both_stacks(info, FALSE);
	else if (ft_strncmp(movement, "rra\n", 4) == 0)
		reverse_rotate_stack_a(info, FALSE);
	else if (ft_strncmp(movement, "rrb\n", 4) == 0)
		reverse_rotate_stack_b(info, FALSE);
	else if (ft_strncmp(movement, "rrr\n", 4) == 0)
		reverse_rotate_both_stacks(info, FALSE);
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	read_line(t_info *info)
{
	char	*movement;

	movement = get_next_line(STDIN);
	while (movement)
	{
		if (!apply_movement(info, movement))
		{
			ft_free(&movement, 1);
			destroy_stack(&info->stack[B]);
			return (FALSE);
		}
		ft_free(&movement, 1);
		movement = get_next_line(STDIN);
	}
	destroy_stack(&info->stack[B]);
	return (TRUE);
}

static int	checker(t_stack **stack_a)
{
	t_info	info;

	if (!(*stack_a))
		return (-1);
	initialise_info(&info, stack_a);
	if (!read_line(&info))
	{
		*stack_a = info.stack[A];
		return (-1);
	}
	*stack_a = info.stack[A];
	return (1);
}

t_stack	*parse_and_fill(int argc, char **argv)
{
	char	***parsed_args;
	t_stack	*stack_a;

	parsed_args = parse_args(argc, argv);
	if (!parsed_args)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	stack_a = fill_stack(parsed_args, 1);
	if (!stack_a)
	{
		ft_free(&parsed_args, 3);
		return (NULL);
	}
	ft_free(&parsed_args, 3);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = parse_and_fill(argc, argv);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (checker(&stack_a) == -1)
	{
		write(2, "Error\n", 6);
		destroy_stack(&stack_a);
		return (2);
	}
	if (!is_sorted(stack_a, 0, stack_len(stack_a)))
	{
		destroy_stack(&stack_a);
		return (3);
	}
	destroy_stack(&stack_a);
	return (0);
}
