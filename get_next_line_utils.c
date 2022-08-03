/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:45:34 by mfirdous          #+#    #+#             */
/*   Updated: 2022/08/03 20:12:52 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Checks if the given string contains a '\n' and returns the index of the '\n' + 1, i.e., the length of the line including the new line.
   For str="abcd\nef", returns 5
            0123 456
*/
int	has_new_line(char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (str[i] == '\n')
			return (i + 1);
	return (0);
}

char *ft_strndup(const char *s, int n)
{
	char	*newStr;
	int		i;

	if (!s)
		return (0);
	newStr = calloc(n, n * sizeof(char));
	if (!newStr)
		return (0);
	i = -1;
	while(++i < n)
		newStr[i] = s[i];
	return (newStr);
}

char	*ft_strnjoin(char **buf, int *len1, char **new_block, int len2)
{
	char	*new_buf;
	int		i;

	new_buf = (char *)calloc((*len1 + len2), (*len1 + len2) * sizeof(char));
	i = -1;
	if (!new_buf)
		return (0);	
	while (++i < *len1)
		new_buf[i] = (*buf)[i];
	while (i < *len1 + len2)
	{	
		new_buf[i] = (*new_block)[i - *len1];
		i++;
	}
	//printf("new_buf= %s\n", new_buf);
	*len1 = i;
	free(*buf);
	free(*new_block);
	return (new_buf);
}

// create final line to return from buf and modify buf to contain the reserve bytes
char *get_line(char **buf, int *buf_len, int line_len)
{
	char *line;
	char *reserve;

	line = ft_strndup(*buf, line_len);
	//printf("line: %s, %d\n", line, line_len);
	reserve = ft_strndup(*buf + line_len, *buf_len - line_len);
	
	free(*buf);
	*buf = reserve;
	*buf_len -= line_len;
	return (line);
}