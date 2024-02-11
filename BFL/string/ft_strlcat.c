/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:07:34 by ribana-b          #+#    #+#             */
/*   Updated: 2023/12/26 22:25:39 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

size_t	ft_strlcat(char *str, const char *str2, size_t bytes)
{
	size_t	strlength;
	size_t	str2length;
	size_t	counter;

	if (!str || !str2)
		return (0);
	strlength = ft_strlen(str);
	str2length = ft_strlen(str2);
	if (strlength >= bytes)
		return (str2length + bytes);
	counter = 0;
	while (str2[counter] && (strlength + counter) < (bytes - 1))
	{
		str[strlength + counter] = str2[counter];
		counter++;
	}
	str[strlength + counter] = '\0';
	return (strlength + str2length);
}
