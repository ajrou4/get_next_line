/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:45:04 by majrou            #+#    #+#             */
/*   Updated: 2023/02/17 23:01:49 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

int	ft_strlen(char *str )
{
	int	l;

	l = 0;
	if (!str)
		return (NULL);
	while (str[l] != '\0')
	{
		l++;
	}
	return (l);
}

char	*my_read( static char	*save)
{
	int		fd;
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!ptr)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, ptr, BUFFER_SIZE + 1);
		if (i == -1)
			break ;
		save = ft_strjoin(save, ptr);
		if (ft_strchr(ptr, '\n'))
			break ;
	}
	free (ptr);
	return (save);
}

char	get_line(static char *s)
{
	char	*book;
	while (s++ != '\0')
	{
		book = my_read(s);
	}
	return (book);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char	*line;
	if(fd < 0)
		retune(NULL);	
	buff = my_read();
	retune ();
}
int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY | O_WRONLY | O_CREAT);
	get_next_line(fd);
}