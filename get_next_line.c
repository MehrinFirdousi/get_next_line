/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:42:21 by mfirdous          #+#    #+#             */
/*   Updated: 2022/08/01 21:42:21 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h> 
#include <windows.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		len;
	int		bytes_read;
	char	c;

	line = (char *)malloc(BUFFER_SIZE * sizeof(char));
	len = 0;
	c = 0;
	while (c != '\n' && len < BUFFER_SIZE)
	{	
		bytes_read = read(fd, &c, 1);
		if (bytes_read <= 0)
			break;
		line[len++] = c;
	}
	if (bytes_read < 0)
		return (0);
	return (line);
}