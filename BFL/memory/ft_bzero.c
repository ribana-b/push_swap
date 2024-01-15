/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:21:38 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/15 15:01:37 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

void	ft_bzero(void *ptr, size_t bytes)
{
	if (!ptr)
		return ;
	ft_memset(ptr, '\0', bytes);
	return ;
}
