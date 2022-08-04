#include "get_next_line.h"

/*TODO:
	- make it return null on:
		1. after reaching end of file
		2. if there is an error while reading
	- should we null terminate the last string if we reach EOF and there was no \n?
	- IMPORTANT: check if EOF counts as an additional character 
	- store bytes_read and length of the new block, use for strnjoin 
	
	
	- move malloc to read_block
	- move line_len line to while condition if possible
*/

void	test(int i)
{
	static char	*res = 0;

	if (res == 0)
	{
		res = (char *)malloc(3 * sizeof(char));
		res[0] = 'a';
		res[1] = 'b';
		res[2] = 0;
		printf("ires=%s\n", res);
	}
	printf("ores=%s\n", res);
	if (i == 2 && res != 0)
		free(res);
}

void	test2(char **buf)
{
	char *new_buf;
	int i = 0;
	new_buf = malloc(11 * sizeof(char));
	
	while(i < 5)
	{
		new_buf[i] = (*buf)[i];
		i++;
	}
	while(i < 10)
	{
		new_buf[i] = 'a';
		i++;
	}
	new_buf[i] = 0;
	free(*buf);
	printf("new_buf = %s\n", new_buf);
	*buf = new_buf;
}
int	main()
{
    int fd = open("a.txt", O_RDONLY);
	int i = -1;
	char *res = (char *)malloc(30 * sizeof(char));
	while(res)
	{
		res = get_next_line(fd);
		printf("\n+%s", res);
		free(res);
	}
	// res[0] = 'h';
	// res[1] = 'i';
	// res[2] = 'j';
	// res[3] = 'k';
	// res[4] = 'l';
	// res[5] = 0;
	// printf("%s\n", res);
	// test2(&res);
	// printf("%s\n", res);
	// free(res);
	return (0);
}