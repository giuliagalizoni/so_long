#include "so_long.h"

#include <stdio.h> //TEMP


int	read_map(char *map_path)
{
	char	*map_line;
	int		map_fd;
	int		count = 0;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return -1;

	map_line = get_next_line(map_fd);
	while (map_line)
	{
		map_line = get_next_line(map_fd);
		count++;
	}

	free(map_line);
	close(map_fd);
	return count;
}

char **make_map_arr(char *map_path)
{
	char	**map_arr;
	int		map_fd;
	int		size;
	int		i = 0;

	size = read_map(map_path);

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return NULL;

	map_arr = malloc(size * sizeof(char *) + 1);

	while (i < size)
	{
		map_arr[i] = get_next_line(map_fd);
		i++;
	}

	map_arr[i] = NULL;

	return map_arr;
}

// int	main()
// {
// 	char size = read_map();
// 	char **arr = make_map_arr(size);
// 	printf("\nreturn: \n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
// 	return 0;
// }
