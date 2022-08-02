#include "get_next_line.h"

/*TODO:
	- make it return null on:
		1. after reaching end of file
		2. if there is an error while reading
	- should we null terminate the last string if we reach EOF and there was no \n?
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

int	main()
{
    int fd = open("a.txt", O_RDONLY);
	int size;
	char *res = (char *)malloc(30 * sizeof(char));
	// do
	// {
	// 	res = get_next_line(fd);
	// 	printf("%s", res);
	// 	free(res);
	// } while (res);

	size = read(fd, res, 7);
	printf("%s\n%d\n", res, size);
	free(res);
	return (0);
}