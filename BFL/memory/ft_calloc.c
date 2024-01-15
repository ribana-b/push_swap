/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:17:59 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 14:59:35 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

void	*ft_calloc(size_t bytes, size_t sizetype)
{
	void	*ptr;

	ptr = malloc(bytes * sizetype);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, bytes * sizetype);
	return (ptr);
}
