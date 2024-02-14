/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:28:02 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

void	*ft_memcpy(void *str, const void *str2, size_t bytes)
{
	char	*temp;
	char	*temp2;

	if (!str || !str2)
		return (NULL);
	temp = (char *)str;
	temp2 = (char *)str2;
	while (bytes--)
		temp[bytes] = temp2[bytes];
	return (str);
}
