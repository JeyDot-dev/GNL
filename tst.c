#include "get_next_line.h"
#include <stdio.h>
int	main(void)
{
	int test;
	test = open("filetest.txt", O_RDONLY);
	printf("%s\n", get_next_line(test));
	printf("%s\n", get_next_line(test));
	printf("%s\n", get_next_line(test));
	printf("%s\n", get_next_line(test));
	printf("%s\n", get_next_line(test));
	printf("%s\n", get_next_line(test));
	printf("%s\n", get_next_line(test));
	printf("%s\n", get_next_line(test));
	printf("%s\n", get_next_line(test));
	printf("%s\n", get_next_line(test));
}
