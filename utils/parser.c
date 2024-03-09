/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:50:11 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/09 23:27:33 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_isrepeated(long **dump, long number, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		if ((*dump)[index] == number)
			return (true);
		++index;
	}
	(*dump)[index] = number;
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
		else if ((parsed_args[index] == '-' || parsed_args[index] == '+')
				&& counter != 0)
			return (false);
		++index;
	}
	if (!counter)
		return (false);
	return (true);
}

static int	alloc_dump(long **dump, size_t size)
{
	long			*temp;

	if (size == 0)
	{
		*dump = (long *)malloc((size + 1) * sizeof(long));
		if (!(*dump))
			return (0);
	}
	else
	{
		temp = (long *)malloc((size + 1) * sizeof(long));
		if (!temp)
		{
			ft_free(dump, 1);
			return (0);
		}
		ft_memcpy(temp, *dump, size * sizeof(long));
		ft_free(dump, 1);
		*dump = temp;
	}
	return (1);
}

static t_bool	ft_isvalid(char **parsed_args, long **dump)
{
	size_t			index;
	long			number;
	static size_t	size;

	index = 0;
	if (!parsed_args[index])
		return (false);
	while (parsed_args[index])
	{
		if (!alloc_dump(dump, size))
			return (false);
		if (!ft_isnumber(parsed_args[index])
			|| ft_strlen(parsed_args[index]) > 11)
			return (false);
		number = ft_atol(parsed_args[index]);
		if (number < MIN_INT || number > MAX_INT
			|| ft_isrepeated(dump, number, size))
			return (false);
		++index;
		++size;
	}
	return (true);
}

char	***parse_args(int argc, char **argv)
{
	char		***parsed_args;
	int			index;
	static long	*dump;

	if (!argv)
		return (NULL);
	parsed_args = (char ***)malloc(argc * sizeof(char **));
	if (!parsed_args)
		return (NULL);
	index = 0;
	while (index < argc - 1)
	{
		parsed_args[index + 1] = NULL;
		parsed_args[index] = ft_split(argv[index + 1], ' ');
		if (!parsed_args[index])
			return (ft_free(&parsed_args, 3));
		if (!ft_isvalid(parsed_args[index], &dump))
		{
			ft_free(&dump, 1);
			return (ft_free(&parsed_args, 3));
		}
		++index;
	}
	ft_free(&dump, 1);
	return (parsed_args);
}
