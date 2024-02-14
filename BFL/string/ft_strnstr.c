/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:20:10 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

char	*ft_strnstr(const char *str, const char *str2, size_t bytes)
{
	size_t	length;
	char	*temp;

	length = ft_strlen(str2);
	if (!str || !str2 || (!(*str) && *str2))
		return (NULL);
	if (!(*str2))
		return ((char *)str);
	temp = (char *)str;
	while (bytes >= length && bytes--)
	{
		if (ft_strncmp(temp, str2, length) == 0)
			return (temp);
		temp++;
	}
	return (NULL);
}
