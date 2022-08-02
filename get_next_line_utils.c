/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:45:34 by mfirdous          #+#    #+#             */
/*   Updated: 2022/08/02 21:39:32 by mfirdous         ###   ########.fr       */
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
	newStr = malloc(n * sizeof(char));
	if (!newStr)
		return (0);
	i = -1;
	while(++i < n)
		newStr[i] = s[i];
	return (newStr);
}


char *ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*res;
	
	if (!s1 && !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, len1 + len2 + 1);
	ft_strlcat(res, s2, len1 + len2 + 1);
	return (res);
}