//#include "get_next_line.h"
#include "get_next_line_bonus.h"
/*TODO:
	- make it return null on:
		1. after reaching end of file
		2. if there is an error while reading
	- should we null terminate the last string if we reach EOF and there was no \n?
	- IMPORTANT: check if EOF counts as an additional character 
	- store bytes_read and length of the new block, use for strnjoin 
	
	- move line_len line to while condition if possible
*/

void test()
{
	static t_file file;
	printf("file fd = %d\n", file.fd);
	printf("file buf = %s\n", file.buf);
	if (file.fd == 0)
	{
		file.fd = 1;
		file.buf = (char *)malloc(10 * sizeof(char));
		file.buf[9] = 0;
		for (int i = 0; i < 9; i++)
			file.buf[i] = i + 65 + file.fd;
		printf("%s\n", file.buf);
	}
	else
	{
		file.buf[0] = 'X';
		printf("%s\n", file.buf);
	}
}
int	main()
{
    int fd1 = open("a.txt", O_RDONLY);
    int fd2 = open("b.txt", O_RDONLY);
    int fd3 = open("c.txt", O_RDONLY);
	char *res;
	int i = -1;
	do
	{
		res = get_next_line(fd1);
		printf("a: %s", res);
		free(res);
		i++;
		res = get_next_line(fd2);
		printf("b: %s", res);
		free(res);
		
		res = get_next_line(fd3);
		printf("c: %s", res);
		free(res);
	} while(res);

	return (0);
}