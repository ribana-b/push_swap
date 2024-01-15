/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:12:27 by ribana-b          #+#    #+#             */
/*   Updated: 2023/10/04 13:32:16 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

char	*ft_strjoin(const char *str, const char *str2)
{
	char	*newstr;
	int		index;
	int		index2;

	index = ft_strlen(str);
	index2 = ft_strlen(str2);
	newstr = (char *)malloc((index + index2 + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	newstr[index + index2] = '\0';
	while (index2--)
		newstr[index + index2] = str2[index2];
	while (index--)
		newstr[index] = str[index];
	return (newstr);
}
