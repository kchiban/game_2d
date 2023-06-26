/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:53:21 by kchiban           #+#    #+#             */
/*   Updated: 2023/03/18 19:19:38 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reading_fd(int fd, char *stash)
{
	char	*buffer;
	int		readed;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(stash, '\n') && readed != 0)
	{
		readed = (int)read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (free(stash), NULL);
		}
		buffer[readed] = '\0';
		stash = ft_strjoin (stash, buffer);
	}
	if (readed == 0)
	{
		if (*stash)
			return (free(buffer), stash);
		return (free(buffer), free(stash), NULL);
	}
	return (free (buffer), stash);
}

char	*ft_next(char *line)
{
	int		i;
	char	*buffer;

	i = 0;
	if (!line)
		return (NULL);
	if (!line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	i += (line[i] == '\n');
	buffer = malloc(sizeof(char) * (i + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		buffer[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	free(line);
	return (buffer);
}

char	*ft_save(char *line)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	if (!line || !line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	i += (line[i] == '\n');
	buffer = malloc(sizeof(char) * (int)(ft_strlen(line) - i) + 1);
	if (!buffer)
		return (NULL);
	while (line[i])
	{
		buffer[j] = line[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*hold = NULL;
	char		*line;
	char		*hello;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = reading_fd(fd, hold);
	hold = ft_save(line);
	hello = ft_next(line);
	return (hello);
}
