/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:35:31 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

char	*ft_strrchr(const char *str, int character)
{
	size_t	length;

	if (!str)
		return (NULL);
	if (!(*str) && character == '\0')
		return ((char *)str);
	length = ft_strlen(str) + 1;
	while (length-- > 0)
		if ((unsigned char)str[length] == (unsigned char)character)
			return ((char *)str + length);
	return (NULL);
}
