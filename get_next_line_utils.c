/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:45:34 by mfirdous          #+#    #+#             */
/*   Updated: 2022/08/04 20:50:26 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Checks if the given string contains a '\n' and returns the index of the '\n' + 1, i.e., the length of the line including the new line.
   For str="abcd\nef", returns 5
            0123 456
*/

// reads a block of BUFFER_SIZE bytes from fd into buf and null terminates the string

int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	has_new_line(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		//i++;
	}
	return (0);
}

char *ft_strndup(const char *s, int n)
{
	char	*newStr;
	int		i;

	if (!s) // maybe remove
		return (0);
	newStr = malloc((n + 1) * sizeof(char));
	if (!newStr)
		return (0);
	i = -1;
	while(++i < n)
		newStr[i] = s[i];
	newStr[i] = 0;
	return (newStr);
}

char	*ft_strnjoin(char **buf, char **new_block)
{
	char	*new_buf;
	int		i;
	int		len1;
	int		len2;

	len1 = ft_strlen(*buf);
	len2 = ft_strlen(*new_block);
	new_buf = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!new_buf)
		return (0);
	i = -1;
	while (++i < len1)
		new_buf[i] = (*buf)[i];
	while (i < len1 + len2)
	{
		new_buf[i] = (*new_block)[i - len1];
		i++;
	}
	new_buf[i] = 0;
	free(*buf);
	free(*new_block);
	return (new_buf);
}

// create final line to return from buf and modify buf to contain the reserve bytes
char *get_line(char **buf, char **new_block, int bytes_read, int line_len)
{
	char	*line;
	char	*reserve;
	int		buf_len;
	int		final_len;
	
	*buf = ft_strnjoin(buf, new_block);
	//printf("GLbuf = %s\n", *buf);
	buf_len = ft_strlen(*buf);
	final_len = buf_len - bytes_read + line_len;
	line = ft_strndup(*buf, final_len);
	
	//printf("line: %s, %d\n", line, final_len);
	reserve = ft_strndup(*buf + final_len, bytes_read - line_len);
	free(*buf);
	*buf = reserve;
	return (line);
}