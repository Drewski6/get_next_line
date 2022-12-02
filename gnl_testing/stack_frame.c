#include <stdlib.h>

char	*return_string(void)
{
	char	*str;
	str = (char *)malloc(10);
	return (str);
}

int foo (int n)
{
	static char *here;
	here = 0;
	here = return_string();
	return (n + 1);
}

int main (void)
{
	int	n;

	n = 0;
	n = foo(n);
	return (0);
}
