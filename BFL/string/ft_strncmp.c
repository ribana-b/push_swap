/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:56:36 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

int	ft_strncmp(const char *str, const char *str2, size_t bytes)
{
	int	index;

	if (!str || !str2)
		return (-1);
	index = 0;
	while (bytes-- && (str[index] || str2[index]))
	{
		if (str[index] != str2[index])
			return ((unsigned char)str[index] - (unsigned char)str2[index]);
		index++;
	}
	return (0);
}
