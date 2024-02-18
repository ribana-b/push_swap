/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:09:53 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		counter;

	if (!str)
		return (NULL);
	counter = ft_strlen(str);
	new_str = (char *)malloc((counter + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[counter] = '\0';
	while (counter-- > 0)
		new_str[counter] = str[counter];
	return (new_str);
}
