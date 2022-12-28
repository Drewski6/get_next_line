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
//	int		fd1;
	int		fd2;

//	fd1 = open("../gnl_working/tripouille/files/multiple_nlx5", O_RDONLY);
	fd2 = open("sample.txt", O_RDONLY);
	i = 0;
	while (i < 25)
	{
//		string = get_next_line(fd1);
//		if (string)
//			printf("%s", string);
//		free(string);
		string = get_next_line(fd2);
		if (string)
			printf("%s", string);
		free(string);
		i++;
	}
//	close(fd1);
	close(fd2);

	return (0);
}
