/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:42:21 by mfirdous          #+#    #+#             */
/*   Updated: 2022/08/03 20:47:46 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = 0;
	char		*new_block;
	static int	bytes_read;
	int			line_len;	// contains the length of a line till (and including) \n
	static int	buf_len = 0;
	int			i = -1;
	if (buf == 0)
	{
		buf = (char *)calloc(BUFFER_SIZE, BUFFER_SIZE * sizeof(char)); // MALLOCS	
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf_len = bytes_read;
	}
	line_len = has_new_line(buf, buf_len);
	//printf("\n\tobuf = %s\n", buf);
	while (!line_len && bytes_read > 0) // is not a line 
	{
		new_block = (char *)calloc(BUFFER_SIZE, BUFFER_SIZE * sizeof(char)); // MALLOCS
		bytes_read = read(fd, new_block, BUFFER_SIZE);
		//printf("\t-newblock = %s, %d\n", new_block, bytes_read);
		line_len = has_new_line(new_block, bytes_read);
		//printf("\tline_len=%d\n", line_len);
		//printf("\tbytes_read=%d\n", bytes_read);
		buf = ft_strnjoin(&buf, &buf_len, &new_block, bytes_read); // MALLOCS new buf and FREES old buf and new block
		//printf("\t-buf = %s, %d\n", buf, buf_len);
	}
	if (bytes_read <= 0 && !buf_len)
		return (0);
	return (get_line(&buf, &buf_len, buf_len - bytes_read + line_len));
}