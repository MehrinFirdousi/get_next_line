/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:27:52 by mfirdous          #+#    #+#             */
/*   Updated: 2022/08/05 18:27:52 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	read_block(int fd, char **block)
{
	int	bytes_read;

	*block = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(*block))
		return (0);
	bytes_read = read(fd, *block, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(*block);
		*block = 0;
	}
	else
		(*block)[bytes_read] = 0;
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char		*buf[2000];
	char			*new_block;
	int				bytes_read;
	int				line_len;

	if (!buf[fd] || !buf[fd][0])
		bytes_read = read_block(fd, &buf[fd]);
	else
		bytes_read = ft_strlen(buf[fd]);
	line_len = has_new_line(buf[fd]);
	while (line_len == 0 && bytes_read > 0)
	{
		bytes_read = read_block(fd, &new_block);
		line_len = has_new_line(new_block);
		buf[fd] = ft_strnjoin(&buf[fd], &new_block);
	}
	if (bytes_read <= 0 && !buf[fd])
		return (0);
	return (get_line(&buf[fd], bytes_read, line_len));
}
