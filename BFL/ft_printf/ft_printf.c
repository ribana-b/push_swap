/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:00:45 by ribana-b          #+#    #+#             */
/*   Updated: 2023/12/12 17:44:23 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"
#include <stdio.h>

void	ft_print_format(const char *str, va_list arg, int *bytes, int *success)
{
	if (*str == '%')
		*success += ft_putchar_fd(*str, 1);
	else if (*str == 'c')
		*success += ft_putchar_fd(va_arg(arg, int), 1);
	else if (*str == 's')
		*success += ft_putstr_fd(va_arg(arg, char *), 1);
	else if (*str == 'd' || *str == 'i')
		*success += ft_putnbr_fd(va_arg(arg, int), 1);
	else if (*str == 'u')
		*success += ft_putunbr_fd(va_arg(arg, unsigned int), 1);
	else if (*str == 'x')
		*success += ft_puthexl_fd(va_arg(arg, unsigned int), 1);
	else if (*str == 'x')
		*success += ft_puthexu_fd(va_arg(arg, unsigned int), 1);
	else if (*str == 'p')
		*success += ft_putaddress_fd(va_arg(arg, unsigned long), 1);
	*bytes += *success;
	return ;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		bytes;
	int		success;
	va_list	arg;

	va_start(arg, str);
	i = -1;
	bytes = 0;
	while (str[++i])
	{
		success = 0;
		if (str[i] == '%')
			ft_print_format(&str[++i], arg, &bytes, &success);
		else
		{
			success = ft_putchar_fd(str[i], 1);
			bytes += success;
		}
		if (success < 0)
			return (-1);
	}
	va_end(arg);
	return (bytes);
}
