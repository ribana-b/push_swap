/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:10:29 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

int	ft_putaddress_fd(unsigned long long ptr, int fd)
{
	int	success;
	int	bytes_written;

	bytes_written = 0;
	success = ft_putstr_fd("0x", fd);
	if (success < 0)
		return (-1);
	bytes_written += success;
	success = ft_puthexl_fd(ptr, fd);
	if (success < 0)
		return (-1);
	bytes_written += success;
	return (bytes_written);
}
