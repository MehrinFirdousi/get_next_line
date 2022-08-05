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
	int bytes_read;

	*block = malloc((BUFFER_SIZE + 1) * sizeof(char));
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


char	*check_fd(int fd, t_file **files)
{
	t_file	*node;

	node = *files;
	while (node)
	{
		if (node->fd == fd)
			return (node->buf);
		node = node->next;
	}
	node = (t_file *)malloc(sizeof(t_file));
	node->fd = fd;
	node->buf = 0;
	if(*files)
		node->next = (*files);
	else
		node->next = 0;
	(*files) = node;
	return (node->buf);
}

void	free_node(int fd, t_file **files)
{
	t_file	*curr_node;
	t_file	*prev_node;

	curr_node = *files;
	prev_node = *files;
	while (curr_node)
	{
		if (curr_node->fd == fd)
		{
			prev_node->next = curr_node->next;
			free(curr_node);
			return ;
		}
		prev_node = curr_node;
		curr_node = curr_node->next;
	}
}

char	*get_next_line(int fd)
{
	static t_file *files;
	char		*buf;
	char		*new_block;
	int			bytes_read;
	int			line_len;

	buf = check_fd(fd, &files);
	if (!buf || !buf[0])
		bytes_read = read_block(fd, &buf);
	else
		bytes_read = ft_strlen(buf);
	line_len = has_new_line(buf);
	while (line_len == 0 && bytes_read > 0)
	{
		bytes_read = read_block(fd, &new_block);	
		line_len = has_new_line(new_block);
		buf = ft_strnjoin(&buf, &new_block);
	}
	if (bytes_read <= 0 && !buf) // nothing to read and buffer is empty
	{
		free_node(fd, &files);
		return (0);
	}
	return (get_line(&buf, bytes_read, line_len));
	return 0;
}