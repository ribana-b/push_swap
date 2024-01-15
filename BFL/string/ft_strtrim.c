/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:47:46 by ribana-b          #+#    #+#             */
/*   Updated: 2023/11/16 14:00:37 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

char	*ft_strtrim(const char *str, const char *str2)
{
	size_t	start;
	size_t	end;

	if (!str || !str2)
		return (NULL);
	if (!(*str))
		return (ft_calloc(1, 1));
	start = 0;
	while (ft_strchr(str2, str[start]))
		start++;
	end = ft_strlen(str);
	while (ft_strchr(str2, str[end]))
		end--;
	return (ft_substr(str, start, end - start + 1));
}
