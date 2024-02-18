/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:33:44 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	index;

	if (!str || !f)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	index = 0;
	while (str[index])
	{
		new_str[index] = f(index, str[index]);
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
