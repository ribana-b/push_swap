/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:12:27 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

char	*ft_strjoin(const char *str, const char *str2)
{
	char	*new_str;
	int		index;
	int		index2;

	index = ft_strlen(str);
	index2 = ft_strlen(str2);
	new_str = (char *)malloc((index + index2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[index + index2] = '\0';
	while (index2--)
		new_str[index + index2] = str2[index2];
	while (index--)
		new_str[index] = str[index];
	return (new_str);
}
