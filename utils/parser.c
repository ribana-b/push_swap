/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:50:11 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/15 11:39:48 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_repeated(long number)
{
	static long	dump[DUMP_LIMIT];
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

static t_bool	is_valid(char **parsed_args)
{
	size_t	index;
	long	number;

	index = 0;
	while (parsed_args[index])
	{
		number = ft_atol(parsed_args[index]);
		if (number < -2147483648 || number > 2147483647 || is_repeated(number))
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
		if (!is_valid(parsed_args[index]))
			return (ft_free(&parsed_args, 3));
		index++;
	}
	parsed_args[index] = NULL;
	return (parsed_args);
}
