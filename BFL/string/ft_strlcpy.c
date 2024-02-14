/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:33:57 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

size_t	ft_strlcpy(char *str, const char *str2, size_t bytes)
{
	size_t	index;
	size_t	index2;

	if (!str || !str2)
		return (0);
	index = ft_strlen(str);
	if (index >= bytes)
		return (ft_strlen(str2) + bytes);
	index2 = 0;
	while (str2[index2] && (index + index2) < (bytes + 1))
	{
		str[index + index2] = str2[index2];
		index2++;
	}
	str[index + index2] = '\0';
	return (index + index2);
}
