/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:42:21 by mfirdous          #+#    #+#             */
/*   Updated: 2022/08/02 21:36:52 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = 0;
	char		*new_block;
	char		*tmp_buf;
	int			bytes_read;
	int			line_len;

	if (buf == 0)
		buf = (char *)malloc(BUFFER_SIZE * sizeof(char)); // MALLOCS
	bytes_read = read(fd, buf, BUFFER_SIZE);
	line_len = has_new_line(buf, bytes_read);
	while (!line_len) // is not a line 
	{
		new_block = (char *)malloc(BUFFER_SIZE * sizeof(char)); // MALLOCS
		bytes_read += read(fd, new_block, BUFFER_SIZE);
		tmp_buf = ft_strjoin(buf, new_block); // MALLOCS
		free(buf); // do both these frees when rewriting strjoin
		free(new_block); //
		buf = tmp_buf;
		line_len = has_new_line(buf, bytes_read);
	}
	if (bytes_read <= 0)
	{
		//free(buf); // IF YOU'RE SEGFAULTING IT COULD BE THIS
		return (0);
	}
	tmp_buf = ft_strndup(buf, line_len); // MALLOCS
	new_block = ft_strndup(buf + line_len, bytes_read - line_len);
	free(buf);
	buf = new_block;
	return (tmp_buf);
}