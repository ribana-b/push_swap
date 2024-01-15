/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:10:29 by ribana-b          #+#    #+#             */
/*   Updated: 2023/12/12 17:36:51 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

int	ft_putaddress_fd(unsigned long long ptr, int fd)
{
	int	success;
	int	byteswritten;

	byteswritten = 0;
	success = ft_putstr_fd("0x", fd);
	if (success < 0)
		return (-1);
	byteswritten += success;
	success = ft_puthexl_fd(ptr, fd);
	if (success < 0)
		return (-1);
	byteswritten += success;
	return (byteswritten);
}
