//#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>


int	main()
{
    int fd1 = open("a.txt", O_RDONLY);
    int fd2 = open("b.txt", O_RDONLY);
    int fd3 = open("c.txt", O_RDONLY);
	char *res1, *res2, *res3;
	int i = -1;
	do
	{
		res1 = get_next_line(fd1);
		printf("a: %s", res1);
		free(res1);

		res2 = get_next_line(fd2);
		printf("b: %s", res2);
		free(res2);
		
		res3 = get_next_line(fd3);
		printf("c: %s", res3);
		free(res3);
	} while(res1 || res2 || res3);

	return (0);
}