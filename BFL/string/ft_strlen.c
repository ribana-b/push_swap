/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:09:30 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/16 10:42:05 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

size_t	ft_strlen(const char *str)
{
	int	counter;

	if (str == NULL)
		return (0);
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}
