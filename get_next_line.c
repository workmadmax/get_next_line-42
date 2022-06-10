/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:08:44 by mdouglas          #+#    #+#             */
/*   Updated: 2022/06/10 18:42:50 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_read(int fd, char *str)
{
    char    *s_temp;
    int     i;
    
    s_temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!s_temp)
        return (NULL);
    i = 1;
    while (!ft_strchr(str, '\n') && i != 0)
    {
        i = read(fd, s_temp, BUFFER_SIZE);
        if (i == -1)
        {
            free(s_temp);
            return (NULL);
        }
        s_temp[i] = '\0';
        str = gnl_strjoin(str, s_temp);
    }
    free(s_temp);
    return (str);
}

char    *get_string(char *str)
{
    char    *s_temp;
    int     i;
    
    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    s_temp = (char *)malloc(sizeof(char) * (i + 2));
    if (!s_temp)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        s_temp[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        s_temp[i] = str[i];
        i++;
    }
    s_temp[i] = '\0';
    return (s_temp);
}

char    *get_next_line(int fd)
{
    char        *str;
    static char *buf;

    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
        return (NULL);
    buf = get_read(fd, buf);
    if (!buf)
        return (NULL);
    str = get_string(buf);
    buf = gnl_dup(buf);
    return (str);
}
