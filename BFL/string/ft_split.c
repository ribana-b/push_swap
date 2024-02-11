/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:32:56 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/11 06:12:11 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

static char	**free_split(char **split)
{
	size_t	index;

	index = 0;
	while (split[index] != NULL)
		free(split[index++]);
	free(split);
	return (NULL);
}

static size_t	count_word(const char *str, char delimit)
{
	size_t	counter;
	size_t	index;

	if (!str)
		return (0);
	counter = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == delimit)
			index++;
		else
		{
			counter++;
			while (str[index] != delimit && str[index] != '\0')
				index++;
		}
	}
	return (counter);
}

static char	*get_word(const char *str, char delimit, size_t *j)
{
	char	*word;
	size_t	index;

	index = 0;
	while (str[*j + index] != '\0' && str[*j + index] != delimit)
		index++;
	word = (char *)malloc((index + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	index = 0;
	while (str[*j] != '\0' && str[*j] != delimit)
	{
		word[index] = str[*j];
		index++;
		(*j)++;
	}
	word[index] = '\0';
	return (word);
}

char	**ft_split(const char *str, char delimit)
{
	char	**split;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	split = (char **)malloc((count_word(str, delimit) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == delimit)
			j++;
		else
		{
			split[i] = get_word(str, delimit, &j);
			if (split[i] == NULL)
				return (free_split(split));
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
