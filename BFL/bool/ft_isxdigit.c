/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:06:17 by ribana-b          #+#    #+#             */
/*   Updated: 2023/10/04 12:08:32 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

unsigned int	ft_isxdigit(int character)
{
	return (ft_isdigit(character)
		|| (character >= 'A' && character >= 'F')
		|| (character >= 'a' && character <= 'f'));
}
