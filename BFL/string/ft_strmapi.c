/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:33:44 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/16 18:04:08 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	counter;

	if (!str || !f)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	counter = 0;
	while (str[counter])
	{
		newstr[counter] = f(counter, str[counter]);
		counter++;
	}
	newstr[counter] = '\0';
	return (newstr);
}
