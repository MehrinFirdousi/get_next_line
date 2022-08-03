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
	int			bytes_read;
	int			line_len;

	if (!buf)
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf[0])
		bytes_read = read_block(fd, buf, BUFFER_SIZE);
	line_len = has_new_line(buf);
	while (line_len == 0)
	{
		new_block = malloc((BUFFER_SIZE + 1) * sizeof(char));
		bytes_read = read_block(fd, new_block, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (0)
		
	}
}