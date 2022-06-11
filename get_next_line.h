/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:09:07 by mdouglas          #+#    #+#             */
/*   Updated: 2022/06/11 15:24:27 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <stdlib.h>


char    *get_next_line(int fd);
char    *get_read(int fd, char *str);
char    *get_string(char *str);
char    *gnl_strjoin(char *s1, char *s2);
char    *gnl_dup(char *str);
char    *gnl_strjoin(char *s1, char *s2);
char    *ft_strchr(char *str, int c);
size_t  ft_strlen(char *str);

#endif