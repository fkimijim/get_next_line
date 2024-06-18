/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkimijim <fkimijim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:20:25 by fkimijim          #+#    #+#             */
/*   Updated: 2024/05/15 16:58:00 by fkimijim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE > INT_MAX
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strdup(char *s1);
char	*get_output_line(char *saved_line);
char	*read_file(int fd, char *saved_line);
char	*get_splitted_line(char *saved_line);
char	*get_next_line(int fd);

#endif