#include "../gnl_working/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (void)
{
	char	*string;
	int		fd;

	fd = open("output.csv", O_RDONLY);
	string = get_next_line(fd);
	printf("Return:%s\n", string);

	free(string);
	close(fd);

	return (0);
}
