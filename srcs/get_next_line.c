/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:08:44 by mdouglas          #+#    #+#             */
/*   Updated: 2023/05/20 10:12:43 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read(int fd, char *str)
{
	char	*buf;
	int		i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		str = gnl_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_string(char *str)
{
	char	*buf;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	buf = (char *)malloc(sizeof(char) * (i + 2));
	if (!buf)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		buf[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buf = get_read(fd, buf);
	if (!buf)
		return (NULL);
	str = get_string(buf);
	buf = gnl_dup(buf);
	return (str);
}
