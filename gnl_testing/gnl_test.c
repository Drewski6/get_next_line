//#include "../gnl_working/get_next_line_bonus.h"
#include "../../Libft/libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (void)
{
	char	*string;
	int		i;
	int		fd1;
	int		fd2;

	fd1 = open("sample.txt", O_RDONLY);
	fd2 = open("sample2.txt", O_RDONLY);
	i = 0;
	while (i < 25)
	{
		string = get_next_line(fd1);
		if (string)
			printf("%s", string);
		free(string);
		string = get_next_line(fd2);
		if (string)
			printf("%s", string);
		free(string);
		i++;
	}
	close(fd1);
	close(fd2);

	return (0);
}
