/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:47:01 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 18:00:16 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

char	*ft_strchr(const char *str, int character)
{
	size_t	counter;

	if (!str)
		return (NULL);
	counter = 0;
	while (str[counter])
	{
		if ((unsigned char)str[counter] == (unsigned char)character)
			return ((char *)str + counter);
		counter++;
	}
	if ((unsigned char)character == '\0')
		return ((char *)str + counter);
	return (NULL);
}
