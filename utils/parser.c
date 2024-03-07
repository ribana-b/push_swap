/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:50:11 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/07 09:32:43 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_isrepeated(long number)
{
	static long		dump[DUMP_LIMIT];
	static size_t	limit;
	size_t			index;

	index = 0;
	while (index < limit)
	{
		if (dump[index] == number)
			return (true);
		index++;
	}
	dump[limit] = number;
	limit++;
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

static t_bool	ft_isvalid(char **parsed_args)
{
	size_t	index;
	long	number;

	index = 0;
	while (parsed_args[index])
	{
		if (!ft_isnumber(parsed_args[index]))
			return (false);
		number = ft_atol(parsed_args[index]);
		if (number < MIN_INT || number > MAX_INT || ft_isrepeated(number))
			return (false);
		index++;
	}
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
		index++;
	}
	parsed_args[index] = NULL;
	return (parsed_args);
}
