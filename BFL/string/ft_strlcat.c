/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:07:34 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 17:14:49 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

size_t	ft_strlcat(char *str, const char *str2, size_t bytes)
{
	size_t	strlenght;
	size_t	str2lenght;
	size_t	counter;

	if (!str || !str2)
		return (0);
	strlenght = ft_strlen(str);
	str2lenght = ft_strlen(str2);
	if (strlenght >= bytes)
		return (str2lenght + bytes);
	counter = 0;
	while (str2[counter] && (strlenght + counter) < (bytes - 1))
	{
		str[strlenght + counter] = str2[counter];
		counter++;
	}
	str[strlenght + counter] = '\0';
	return (strlenght + str2lenght);
}
