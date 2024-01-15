/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:27:01 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 15:01:03 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

void	ft_memset(void *ptr, int character, size_t bytes)
{
	char	*newptr;

	if (!ptr)
		return ;
	newptr = (char *)ptr;
	while (bytes-- > 0)
		newptr[bytes] = character;
	return ;
}
