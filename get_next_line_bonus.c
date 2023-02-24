/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:24:53 by majrou            #+#    #+#             */
/*   Updated: 2023/02/24 01:49:03 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*my_read(int fd, char *save)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!ptr)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, ptr, BUFFER_SIZE);
		if (i != -1)
			ptr[i] = '\0';
		if (i == 0)
			break ;
		if (i == -1)
		{
			free(save);
			save = NULL;
			break ;
		}
		save = ft_strjoin(save, ptr);
		if (ft_strchr(ptr, '\n'))
			break ;
	}
	return (free(ptr), save);
}

char	*ft_line(char *save)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_substr(save, 0, i + 1);
	return (line);
}

char	*sub(char *save)
{
	char	*sub;
	size_t	i;
	size_t	len;

	sub = NULL;
	i = 0;
	len = ft_strlen(save);
	while (save[i] && save[i] != '\n')
		i++;
	if (i < len - 1)
		sub = ft_substr(save, i + 1, len);
	free(save);
	return (sub);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;

	line = NULL;
	str[fd] = my_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_line(str[fd]);
	str[fd] = sub(str[fd]);
	return (line);
}
/*int main()
{
	int fd = open("ajrou.txt", O_RDONLY);
	//char *hello = "Hello World\n";
   	//printf("%s",get_line(hello));
	//printf("%s",sub(hello));
get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

}*/