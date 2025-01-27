#include "../so_long.h"

int	flood_fill(char **map, int x, int y, t_vars *vars)
{
	if (x < 0 || x >= vars->map.width || y < 0 || y >= vars->map.height)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	if (map[y][x] == 'C')
		vars->map.c_reach++;
	if (map[y][x] == 'E')
		vars->map.e++;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, vars);
	flood_fill(map, x - 1, y, vars);
	flood_fill(map, x, y + 1, vars);
	flood_fill(map, x, y - 1, vars);
	return (1);
}

char	**duplicate_map(char **original, int height)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < height)
	{
		copy[y] = ft_strdup(original[y]);
		if (!copy[y])
		{
			while (--y >= 0)
				free(copy[y]);
			free(copy);
			return (NULL);
		}
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

int	validate_map(t_vars *vars)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = duplicate_map(vars->map.arr, vars->map.height / TILE_SIZE);
	if (!map_copy)
		return (error_message("Error: Failed to duplicate map"), 0);
	x = vars->farmer.x / TILE_SIZE;
	y = vars->farmer.y / TILE_SIZE;
	vars->map.c_reach = 0;
	vars->map.e = 0;
	flood_fill(map_copy, x, y, vars);
	if (vars->map.c_reach != vars->map.c || vars->map.e != 1)
	{
		free_map(map_copy);
		return (error_message("Map validation failed: unreachable elements"),
			0);
	}
	free_map(map_copy);
	return (1);
}
