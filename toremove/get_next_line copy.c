/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:42:21 by mfirdous          #+#    #+#             */
/*   Updated: 2022/08/04 20:30:42 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_block(int fd, char *buf)
{
	int bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	buf[bytes_read] = 0;
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*new_block;
	int			bytes_read;
	int			line_len;

	new_block = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read_block(fd, new_block);
	printf("\n\tobuf = %s", buf);
	printf("\n\tonew_block = %s, %d", new_block, bytes_read);
	line_len = has_new_line(new_block);
	printf("\n\tline_len = %d\n", line_len);
	while (line_len == 0 && bytes_read > 0)
	{
		buf = ft_strnjoin(&buf, &new_block); // will free buf and new_block after creating its joined string
		printf("\n\t-buf = %s, %d\n", buf, ft_strlen(buf));
		new_block = malloc((BUFFER_SIZE + 1) * sizeof(char));
		bytes_read = read_block(fd, new_block);	
		printf("\t-newblock = %s, %d\n", new_block, bytes_read);
		line_len = has_new_line(new_block);
	}
	if (bytes_read <= 0)
		return (0);
	return (get_line(&buf, &new_block, bytes_read, line_len));
	return (0);
}