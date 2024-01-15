/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:46:26 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/25 14:53:14 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	counter;

	if (!str || !f)
		return ;
	counter = 0;
	while (str[counter])
	{
		f(counter, str + counter);
		counter++;
	}
	return ;
}
