/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 06:37:12 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:53 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#define MAX_FD 1048576

static char	*next_line(char *line, char *buffer);
static char	*parse_nl(char *s1, size_t len);
static char	*read_nl(char *buffer, int fd);
static void	free_buffer(char **buffer, int fd);

// MAX_FD is the size get from "ulimit -Sn", who shows the soft limit of open
// file descriptors the 42 workspace can have.
char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*new_line;
	size_t		str_len;
	char		*tmp;

	buffer[fd] = read_nl(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	new_line = ft_strchr2(buffer[fd], '\n');
	if (new_line)
		str_len = new_line - buffer[fd];
	else
		str_len = ft_strlen(buffer[fd]);
	if (str_len > __SIZE_MAX__ - 2)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	tmp = parse_nl(buffer[fd], str_len + 1);
	buffer[fd] = next_line(new_line, buffer[fd]);
	free_buffer(buffer, fd);
	return (tmp);
}

static char	*next_line(char *line, char *buffer)
{
	char	*tmp;

	if (!line || !*line)
	{
		free(buffer);
		return (NULL);
	}
	line++;
	tmp = ft_calloc(1, sizeof (*tmp));
	if (!tmp)
		return (NULL);
	if (*line)
		tmp = ft_strjoin2(tmp, line);
	free(buffer);
	return (tmp);
}

static char	*parse_nl(char *s1, size_t len)
{
	char	*tmp;
	char	*ptr_tmp;
	char	*ptr_s1;

	if (!*s1)
		return (NULL);
	ptr_s1 = s1;
	tmp = malloc((len + 1) * sizeof (*tmp));
	if (!tmp)
		return (NULL);
	ptr_tmp = tmp;
	while (len--)
		*ptr_tmp++ = *ptr_s1++;
	*ptr_tmp = '\0';
	return (tmp);
}

static char	*read_nl(char *buffer, int fd)
{
	ssize_t		rd;
	char		*tmp;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof (*buffer));
	if (!tmp)
		return (NULL);
	rd = read(fd, tmp, BUFFER_SIZE);
	while (rd)
	{
		if (rd == -1)
		{
			free(tmp);
			if (buffer)
				free(buffer);
			return (NULL);
		}
		tmp[rd] = '\0';
		buffer = ft_strjoin2(buffer, tmp);
		if (ft_strchr2(buffer, '\n'))
			break ;
		rd = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	return (buffer);
}

static void	free_buffer(char **buffer, int fd)
{
	if (buffer[fd] && buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
}
