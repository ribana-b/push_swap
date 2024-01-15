/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:31:08 by ribana-b          #+#    #+#             */
/*   Updated: 2023/10/04 13:36:03 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

int	ft_putendl_fd(const char *str, int fd)
{
	int	byteswritten;

	if (str == NULL || fd < 0)
		return (-1);
	byteswritten = ft_putstr_fd(str, fd);
	if (byteswritten < 0)
		return (-1);
	byteswritten = ft_putchar_fd('\n', fd);
	if (byteswritten < 0)
		return (-1);
	return (byteswritten);
}
