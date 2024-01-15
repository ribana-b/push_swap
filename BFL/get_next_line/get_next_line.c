/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:11:44 by ribana-b          #+#    #+#             */
/*   Updated: 2023/12/12 18:47:05 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bfl.h"

static char	*ft_strjoin_gnl(char *str, const char *str2)
{
	char	*newstr;
	int		i;
	int		j;

	i = ft_strlen(str);
	j = ft_strlen(str2);
	newstr = (char *)malloc((i + j + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	newstr[i + j] = '\0';
	while (j-- > 0)
		newstr[i + j] = str2[j];
	while (i-- > 0)
		newstr[i] = str[i];
	free(str);
	return (newstr);
}

static char	*read_file(char *temp, int fd)
{
	char	*buffer;
	int		bytesread;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(temp);
		return (NULL);
	}
	bytesread = 1;
	while (bytesread > 0 && ft_strchr(temp, '\n') == NULL)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		temp = ft_strjoin_gnl(temp, buffer);
	}
	free(buffer);
	return (temp);
}

static char	*read_temp(char *temp)
{
	char	*line;
	int		i;

	if (!temp[0])
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = temp[i];
	line[i + 1] = '\0';
	return (line);
}

static char	*read_temp_again(char *temp)
{
	char	*newtemp;
	int		i;
	int		j;

	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\n')
		i++;
	j = 0;
	while (temp[i + j] != '\0')
		j++;
	newtemp = (char *)malloc((j + 1) * sizeof(char));
	if (!newtemp)
		return (NULL);
	j = -1;
	while (temp[i + ++j] != '\0')
		newtemp[j] = temp[i + j];
	newtemp[j] = '\0';
	free(temp);
	return (newtemp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp)
	{
		temp = ft_calloc(1, sizeof(char));
		if (!temp)
			return (NULL);
	}
	temp = read_file(temp, fd);
	if (!temp)
		return (NULL);
	line = read_temp(temp);
	if (!temp[0])
	{
		free(temp);
		temp = NULL;
	}
	temp = read_temp_again(temp);
	return (line);
}
