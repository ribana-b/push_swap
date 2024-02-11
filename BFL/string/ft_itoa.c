/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:32:44 by ribana-b          #+#    #+#             */
/*   Updated: 2023/12/26 22:25:39 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

static int	number_length(int number)
{
	long	temp;
	int		counter;

	if (number < 0)
		temp = (long)number * -1;
	else
		temp = (long)number;
	counter = 1;
	while ((temp / 10) > 0)
	{
		temp /= 10;
		counter++;
	}
	return (counter);
}

static char	*fixed_malloc(int number, size_t bytes)
{
	char	*str;

	if (number < 0)
		str = (char *)malloc((bytes + 2) * sizeof(char));
	else
		str = (char *)malloc((bytes + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static void	number_to_string(char *str, int number, int numberlength)
{
	long	temp;

	if (number < 0)
		temp = (long)number * -1;
	else
		temp = (long)number;
	str[numberlength] = '\0';
	while (numberlength-- > 0)
	{
		str[numberlength] = temp % 10 + '0';
		temp /= 10;
	}
	return ;
}

char	*ft_itoa(int number)
{
	char	*str;
	int		numberlength;

	numberlength = number_length(number);
	str = fixed_malloc(number, numberlength);
	if (!str)
		return (NULL);
	if (number < 0)
	{
		str[0] = '-';
		number_to_string(str + 1, number, numberlength);
	}
	else
		number_to_string(str, number, numberlength);
	return (str);
}
