/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:02:36 by ribana-b          #+#    #+#             */
/*   Updated: 2023/12/12 15:10:28 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

int	ft_putnbr_fd(int number, int fd)
{
	char	*str;
	int		byteswritten;

	if (fd < 0)
		return (-1);
	str = ft_itoa(number);
	if (!str)
		return (-1);
	byteswritten = ft_putstr_fd(str, fd);
	free(str);
	if (byteswritten < 0)
		return (-1);
	return (byteswritten);
}
