/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:17:59 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

void	*ft_calloc(size_t bytes, size_t size_type)
{
	void	*ptr;

	ptr = malloc(bytes * size_type);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes * size_type);
	return (ptr);
}
