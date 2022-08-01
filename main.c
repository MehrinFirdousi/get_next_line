#include <fcntl.h>
#include <windows.h>
#include <stdio.h>
#include "get_next_line.h"

/*TODO:
	- make it return null on:
		1. after reaching end of file
		2. if there is an error while reading
	- should we null terminate the last string if we reach EOF and there was no \n?
*/

int main()
{
    int fd = open("a.txt", O_RDONLY);
	char *res;
	int i = 0;
	do
	{
		res = get_next_line(fd);
		printf("%s\n", res);
		free(res);
	} while (res);
    return 0;
}