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

/* Checks if the given string contains a '\n' and returns the index of the '\n' + 1, i.e., the length of the line including the new line.
   For str="abcd\nef", returns 4
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