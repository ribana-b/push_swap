/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:44:24 by ribana-b          #+#    #+#             */
/*   Updated: 2023/10/04 13:03:25 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

int	ft_putchar_fd(char character, int fd)
{
	int	byteswritten;

	if (fd < 0)
		return (-1);
	byteswritten = write(fd, &character, 1);
	if (byteswritten < 0)
		return (-1);
	return (byteswritten);
}
