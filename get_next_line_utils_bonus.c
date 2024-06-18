/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkimijim <fkimijim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:45:30 by fkimijim          #+#    #+#             */
/*   Updated: 2024/05/13 03:29:59 by kimijimafum      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ans;

	if (!s1)
		s1 = ft_strdup("\0");
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ans = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ans)
		return (free(s1), NULL);
	ft_strlcpy(ans, s1, len_s1 + 1);
	ft_strlcpy(&ans[len_s1], s2, len_s2 + 1);
	return (free(s1), ans);
}

char	*ft_strchr(const char *s, int c)
{
	if (!(char)c)
		return ((char *)(s + ft_strlen(s)));
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)++s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s1_copy;

	s1_copy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s1_copy)
		return (0);
	ft_strlcpy(s1_copy, s1, (ft_strlen(s1) + 1));
	return (s1_copy);
}
