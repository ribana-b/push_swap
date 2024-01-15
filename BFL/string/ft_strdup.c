/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:09:53 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 14:15:49 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	int		counter;

	if (!str)
		return (NULL);
	counter = ft_strlen(str);
	new = (char *)malloc((counter + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[counter] = '\0';
	while (counter-- > 0)
		new[counter] = str[counter];
	return (new);
}
