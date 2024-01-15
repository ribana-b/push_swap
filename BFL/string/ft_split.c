/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:32:56 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/16 18:05:47 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

static char	**free_split(char **str, int counter)
{
	if (!str)
		return (NULL);
	while (counter-- > 0)
	{
		free(str[counter]);
		str[counter] = NULL;
	}
	free(str);
	str = NULL;
	return (NULL);
}

static int	word_counter(const char *str, char character)
{
	char	*temp;
	int		counter;

	if (!str)
		return (0);
	temp = (char *)str;
	counter = 0;
	while (*temp)
	{
		if (*temp != character)
		{
			counter++;
			while (*temp && *temp != character)
				temp++;
		}
		else
			temp++;
	}
	return (counter);
}

static char	*get_word(const char *str, char character)
{
	char	*word;
	int		counter;

	if (!str)
		return (NULL);
	counter = 0;
	while (str[counter] && str[counter] != character)
		counter++;
	word = (char *)malloc((counter + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[counter] = '\0';
	while (counter-- > 0)
		word[counter] = str[counter];
	return (word);
}

static char	**real_split(const char *str, char character)
{
	char	**split;
	int		counter;
	int		wordcounter;

	wordcounter = word_counter(str, character);
	split = (char **)malloc((wordcounter + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	counter = 0;
	while (*str && counter < wordcounter)
	{
		while (*str && *str == character)
			str++;
		split[counter] = get_word(str, character);
		if (!split[counter])
			return (free_split(split, counter));
		counter++;
		while (*str && *str != character)
			str++;
	}
	split[counter] = NULL;
	return (split);
}

char	**ft_split(const char *str, char character)
{
	char	**split;
	char	*temp;

	if (!str)
		return (NULL);
	temp = (char *)str;
	split = real_split(temp, character);
	if (!split)
		return (NULL);
	return (split);
}
