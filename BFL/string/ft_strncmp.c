/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:56:36 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 13:04:15 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

int	ft_strncmp(const char *str, const char *str2, size_t bytes)
{
	int	counter;

	if (!str || !str2)
		return (-1);
	counter = 0;
	while (bytes-- && (str[counter] || str2[counter]))
	{
		if (str[counter] != str2[counter])
			return ((unsigned char)str[counter] - (unsigned char)str2[counter]);
		counter++;
	}
	return (0);
}
