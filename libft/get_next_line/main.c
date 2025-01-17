#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	test0(void)
{
	char	*str;
	int		fd = open("1char.txt", O_RDONLY);
	if (fd == -1)
		return;
	//int i = 10;

	while ((str = get_next_line(fd)))
	{
		printf("line: %s", str);
		free(str);
	}
	close(fd);
}

void	test1(void)
{

	puts("test 1");
	char	*str;
	int		lc = 0;
	int		fd = open("new_lines_only.txt", O_RDONLY);
	if (fd == -1)
		return;

	while ((str = get_next_line(fd)))
	{
		printf("[%2d] line: %s", lc++, str);
		free(str);
	}
	close(fd);

}

int	main()
{
	char	*str;
	int		fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	int count = 0;

	while ((str = get_next_line(fd)))
	{
		printf("line %d: %s", count++ , str);
		free(str);
	}
	close(fd);
	get_next_line(fd);
	return (0);
}
