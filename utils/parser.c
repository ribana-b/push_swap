/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:50:11 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/08 20:38:02 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_isrepeated(int **dump, long number, size_t limit)
{
	size_t	index;

	index = 0;
	while (index < limit)
	{
		if ((*dump)[index] == number)
			return (true);
		++index;
	}
	(*dump)[limit] = number;
	return (false);
}

static t_bool	ft_isnumber(char *parsed_args)
{
	size_t	index;
	size_t	counter;

	index = 0;
	counter = 0;
	while (parsed_args[index])
	{
		if (ft_isdigit(parsed_args[index]))
			++counter;
		else if (parsed_args[index] != '-' && parsed_args[index] != '+')
			return (false);
		++index;
	}
	if (!counter)
		return (false);
	return (true);
}

int	alloc_dump(int **dump, size_t index)
{
	int	*temp;

	if (index == 0)
	{
		*dump = (int *)malloc(1 * sizeof(int));
		if (!(*dump))
			return (0);
	}
	else
	{
		temp = (int *)malloc((index + 1) * sizeof(int));
		if (!temp)
		{
			ft_free(dump, 1);
			return (0);
		}
		ft_memcpy(temp, *dump, index * sizeof(int));
		ft_free(dump, 1);
		*dump = temp;
	}
	return (1);
}

static t_bool	ft_isvalid(char **parsed_args)
{
	size_t		index;
	long		number;
	static int	*dump;

	index = 0;
	while (parsed_args[index])
	{
		if (!alloc_dump(&dump, index))
			return (false);
		if (!ft_isnumber(parsed_args[index]))
		{
			ft_free(&dump, 1);
			return (false);
		}
		number = ft_atol(parsed_args[index]);
		if (number < MIN_INT || number > MAX_INT
			|| ft_isrepeated(&dump, number, index))
		{
			ft_free(&dump, 1);
			return (false);
		}
		++index;
	}
	ft_free(&dump, 1);
	return (true);
}

char	***parse_args(int argc, char **argv)
{
	char	***parsed_args;
	int		index;

	if (!argv)
		return (NULL);
	parsed_args = (char ***)malloc(argc * sizeof(char **));
	if (!parsed_args)
		return (NULL);
	index = 0;
	while (index < argc - 1)
	{
		parsed_args[index] = ft_split(argv[index + 1], ' ');
		if (!parsed_args[index])
			return (ft_free(&parsed_args, 3));
		if (!ft_isvalid(parsed_args[index]))
			return (ft_free(&parsed_args, 3));
		++index;
	}
	parsed_args[index] = NULL;
	return (parsed_args);
}
