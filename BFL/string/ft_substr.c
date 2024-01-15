/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:23 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/16 13:34:10 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

char	*ft_substr(const char *str, size_t start, size_t bytes)
{
	char	*newstr;

	if (!str)
		return (NULL);
	if ((bytes + start) > ft_strlen(str))
		bytes = ft_strlen(str) - start;
	if (start >= ft_strlen(str))
		return (ft_calloc(1, 1));
	newstr = (char *)malloc((bytes + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	newstr[bytes] = '\0';
	while (bytes-- > 0)
		newstr[bytes] = str[start + bytes];
	return (newstr);
}
