#include <stdio.h>
#include <unistd.h>
#include "fd_examine.h"

int main (void)
{
	//printf("i/o    :descriptor\tpointer\t\t\n");
	//printf("stdin  :%d\t\t%p\n", STDIN_FILENO, stdin);
	//printf("stdout :%d\t\t%p\n", STDOUT_FILENO, stdout);
	// printf("stderr :%d\t\t%p\n", STDERR_FILENO, stderr);

	print_file_struct_properties("stdin", stdin);
	//print_file_struct_properties("stdout", stdout);
	//print_file_struct_properties("stderr", stderr);

	return (0);
}
