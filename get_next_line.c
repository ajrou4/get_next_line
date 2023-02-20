/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:45:04 by majrou            #+#    #+#             */
/*   Updated: 2023/02/20 00:54:01 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		ptr[i] = '\0';
		if (i == -1)
			break ;
		save = ft_strjoin(save, ptr);
		if (ft_strchr(ptr, '\n'))
			break ;
	}
	free (ptr);
	return (save);
}

char	*get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	line = ft_substr(save, 0, i);
	return (line);
}

char	*sub(char *save)
{
	char	*sub;
	int		i;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	sub = ft_substr(save, i + 1, ft_strlen(save) - i - 1);
	free(save);
	return (sub);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = my_read(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = sub(str);
	return (line);
}
int main()
{
	int fd = open("majrou.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}