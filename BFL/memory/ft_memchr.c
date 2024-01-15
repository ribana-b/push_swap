/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:44:09 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 15:23:37 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

void	*ft_memchr(const void *ptr, int character, size_t bytes)
{
	unsigned char	*temp;

	if (!ptr)
		return (NULL);
	temp = (unsigned char *)ptr;
	while (bytes--)
	{
		if (*temp == (unsigned char)character)
			return ((void *)temp);
		temp++;
	}
	return (NULL);
}
