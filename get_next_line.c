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
	char	*buf;
	char	*new_block;
	char	*tmp_buf;
	int		bytes_read;
	int		line_len;

	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	bytes_read = read(fd, buf, BUFFER_SIZE);
	line_len = has_new_line(buf, bytes_read);
	while (!line_len) // is not a line 
	{
		new_block = (char *)malloc(BUFFER_SIZE * sizeof(char));
		bytes_read = read(fd, new_block, BUFFER_SIZE);
		tmp_buf = ft_strjoin(buf, new_block);
		free(buf); // do both these frees when rewriting strjoin
		free(new_block); //
		buf = tmp_buf;
		line_len = has_new_line(buf, bytes_read);
	}
	
	if (bytes_read <= 0)
		return (0);
	return (buf);
}