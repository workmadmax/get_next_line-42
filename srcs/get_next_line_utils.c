/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:43:08 by mdouglas          #+#    #+#             */
/*   Updated: 2023/05/20 10:10:01 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	idx;

	idx = 0;
	if (!str)
		return (0);
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

char	*ft_strchr(char *str, int c)
{
	int		idx;
	char	x;

	idx = 0;
	x = (char)c;
	if (!str || c == '\0')
		return (NULL);
	while ((str[idx] != x) && (str[idx] != '\0'))
		idx++;
	if (str[idx] == x)
		return ((char *)(str + idx));
	return (NULL);
}

/*
    strjoin with free s1 "string 1";
*/

char	*gnl_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = '\0';
	}
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s2 || !str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

/*
	strdup with free 'str'
*/

char	*gnl_dup(char *str)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dup)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		dup[j++] = str[i++];
	dup[j] = '\0';
	free(str);
	return (dup);
}
