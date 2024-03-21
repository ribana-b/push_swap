/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:50:11 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/21 02:29:50 by ribana-b         ###   ########.com      */
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
			return (TRUE);
		++index;
	}
	(*dump)[index] = number;
	return (FALSE);
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
			return (FALSE);
		else if ((parsed_args[index] == '-' || parsed_args[index] == '+')
			&& counter != 0)
			return (FALSE);
		++index;
	}
	if (!counter)
		return (FALSE);
	return (TRUE);
}

static int	alloc_dump(long **dump, size_t size)
{
	long	*temp;

	if (size == 0)
	{
		*dump = (long *)malloc((size + 1) * sizeof(long));
		if (!(*dump))
			return (FALSE);
	}
	else
	{
		temp = (long *)malloc((size + 1) * sizeof(long));
		if (!temp)
		{
			ft_free(dump, 1);
			return (FALSE);
		}
		ft_memcpy(temp, *dump, size * sizeof(long));
		ft_free(dump, 1);
		*dump = temp;
	}
	return (TRUE);
}

static t_bool	ft_isvalid(char **parsed_args, long **dump)
{
	size_t			index;
	long			number;
	static size_t	size;

	index = 0;
	while (parsed_args[index])
	{
		if (!alloc_dump(dump, size))
			return (FALSE);
		if (!ft_isnumber(parsed_args[index])
			|| ft_strlen(parsed_args[index]) > 11)
			return (FALSE);
		number = ft_atol(parsed_args[index]);
		if (number < MIN_INT || number > MAX_INT
			|| ft_isrepeated(dump, number, size))
			return (FALSE);
		++index;
		++size;
	}
	return (TRUE);
}

char	***parse_args(int argc, char **argv)
{
	char	***parsed_args;
	int		index;
	long	*dump;

	parsed_args = (char ***)malloc(argc * sizeof(char **));
	dump = NULL;
	if (!parsed_args)
		return (NULL);
	index = 0;
	while (index < argc - 1)
	{
		parsed_args[index + 1] = NULL;
		parsed_args[index] = ft_split(argv[index + 1], ' ');
		if (!parsed_args[index])
			return (ft_free(&parsed_args, 3), ft_free(&dump, 1));
		if (!ft_isvalid(parsed_args[index], &dump))
			return (ft_free(&parsed_args, 3), ft_free(&dump, 1));
		++index;
	}
	ft_free(&dump, 1);
	return (parsed_args);
}
