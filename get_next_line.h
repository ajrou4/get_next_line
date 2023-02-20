/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:43:35 by majrou            #+#    #+#             */
/*   Updated: 2023/02/20 20:11:36 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdio.h>
# include<string.h>
# include<unistd.h>
# include<stdlib.h>
# include <fcntl.h>
# include <limits.h>

# define BUFFER_SIZE 5

char			*get_next_line(int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strdup(const char *str);
char			*my_read(int fd, char *str);
char			*ft_strchr(const char *str, int c);
char			*get_line(char *str);

#endif
