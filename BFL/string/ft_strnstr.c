/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:20:10 by ribana-b          #+#    #+#             */
/*   Updated: 2023/12/10 13:03:45 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

char	*ft_strnstr(const char *str, const char *str2, size_t bytes)
{
	size_t	str2length;
	char	*temp;

	str2length = ft_strlen(str2);
	if (!str || !str2)
		return (NULL);
	if (!(*str2))
		return ((char *)str);
	if (!(*str) && *str2)
		return (NULL);
	temp = (char *)str;
	while (bytes >= str2length && bytes--)
	{
		if (ft_strncmp(temp, str2, str2length) == 0)
			return (temp);
		temp++;
	}
	return (NULL);
}
