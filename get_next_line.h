/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:43:41 by mfirdous          #+#    #+#             */
/*   Updated: 2022/08/03 18:01:38 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//# include <io.h>

char	*get_next_line(int fd);
int		read_block(int fd, char *buf, int size)
int		has_new_line(char *buf);
char	*ft_strndup(const char *s, int n);
char	*ft_strnjoin(char **buf, int *len1, char **new_block, int len2);
char	*get_line(char **buf, int *buf_len, int line_len);

#endif