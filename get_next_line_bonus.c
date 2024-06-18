/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkimijim <fkimijim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:33:13 by fkimijim          #+#    #+#             */
/*   Updated: 2024/05/13 05:05:58 by kimijimafum      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_output_line(char *saved_line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!saved_line[i])
		return (NULL);
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	if (saved_line[i] == '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, saved_line, i + 1);
	return (tmp);
}

char	*read_file(int fd, char *saved_line)
{
	char	*buf;
	ssize_t	byte_num;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		if (saved_line)
			return (free(saved_line), NULL);
		else
			return (NULL);
	}
	byte_num = 1;
	while (ft_strchr(saved_line, '\n') == NULL && byte_num > 0)
	{
		byte_num = read(fd, buf, BUFFER_SIZE);
		if (byte_num < 0)
			return (free(buf), free(saved_line), NULL);
		buf[byte_num] = '\0';
		saved_line = ft_strjoin(saved_line, buf);
	}
	return (free(buf), saved_line);
}

char	*get_splitted_line(char *saved_line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	if (!saved_line[i])
		return (free(saved_line), NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(saved_line) - i + 1));
	if (!tmp)
		return (free(saved_line), NULL);
	ft_strlcpy(tmp, &saved_line[i + 1], (ft_strlen(saved_line) - i + 1));
	return (free(saved_line), tmp);
}

char	*get_next_line(int fd)
{
	static char	*saved_line[OPEN_MAX];
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_line[fd] = read_file(fd, saved_line[fd]);
	if (!saved_line[fd])
		return (NULL);
	output = get_output_line(saved_line[fd]);
	if (!output)
	{
		free(saved_line[fd]);
		saved_line[fd] = NULL;
		return (NULL);
	}
	saved_line[fd] = get_splitted_line(saved_line[fd]);
	return (output);
}
