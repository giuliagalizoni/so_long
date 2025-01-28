/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:45 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/27 15:43:24 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	read_map(char *map_path)
{
	char	*map_line;
	int		map_fd;
	int		count;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (-1);
	map_line = get_next_line(map_fd);
	count = 0;
	while (map_line != NULL)
	{
		free(map_line);
		map_line = get_next_line(map_fd);
		count++;
	}
	free(map_line);
	map_line = NULL;
	close(map_fd);
	return (count);
}

char	**make_map_arr(char *map_path)
{
	char	**map_arr;
	int		map_fd;
	int		size;
	int		i;

	size = read_map(map_path);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (error_message("Error reading map file"), NULL);
	map_arr = malloc((size + 1) * sizeof(char *));
	if (!map_arr)
		return (error_message("Error processing map. Please try again"), NULL);
	i = 0;
	while (i < size)
	{
		map_arr[i] = get_next_line(map_fd);
		i++;
	}
	map_arr[i] = NULL;
	close(map_fd);
	return (map_arr);
}

static void	scan_map(t_vars *vars, int *y, int *x)
{
	*y = 0;
	while (vars->map.arr[*y])
	{
		*x = 0;
		while (vars->map.arr[*y][*x])
		{
			if (vars->map.arr[*y][*x] == '\n')
				vars->map.arr[*y][*x] = '\0';
			else if (vars->map.arr[*y][*x] == 'P')
			{
				vars->map.p++;
				vars->farmer.x = *x * TILE_SIZE;
				vars->farmer.y = *y * TILE_SIZE;
			}
			else if (vars->map.arr[*y][*x] == 'C')
				vars->map.c++;
			else if (vars->map.arr[*y][*x] == 'E')
				vars->map.e++;
			else if (vars->map.arr[*y][*x] != '0'
				&& vars->map.arr[*y][*x] != '1')
				vars->map.invalid = 1;
			(*x)++;
		}
		(*y)++;
	}
}

void	init_map(t_vars *vars, char *map_path)
{
	int	y;
	int	x;

	vars->map.arr = make_map_arr(map_path);
	vars->map.c = 0;
	vars->map.e = 0;
	vars->map.p = 0;
	vars->map.end = 0;
	vars->map.invalid = 0;
	scan_map(vars, &y, &x);
	vars->map.width = (x - 1) * TILE_SIZE;
	vars->map.height = y * TILE_SIZE;
	vars->farmer.mov_count = 0;
	check_map(vars);
	if (!validate_map(vars))
		cleanup(vars);
}
