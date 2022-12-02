#include "../gnl_working/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (void)
{
	char	*string;
	int		i;
	int		fd;

	fd = open("output.csv", O_RDONLY);
	i = 0;
	while (i < 25)
	{
		string = get_next_line(fd);
		printf("Return:%s\n", string);
		i++;
	}
	free(string);
	close(fd);

	return (0);
}
