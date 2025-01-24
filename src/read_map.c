/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:45 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/24 18:27:44 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static char	**make_map_arr(char *map_path)
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
			if (vars->map.arr[*y][*x] == 'P')
			{
				vars->farmer.x = *x * TILE_SIZE;
				vars->farmer.y = *y * TILE_SIZE;
			}
			if (vars->map.arr[*y][*x] == 'C')
				vars->map.c++;
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
	vars->map.end = 0;
	scan_map(vars, &y, &x);
	vars->map.width = (x - 1) * TILE_SIZE;
	vars->map.height = y * TILE_SIZE;
	vars->farmer.mov_count = 0;
	check_map(vars);
}

void	free_map(char **arr)
{
	int	y;

	if (!arr)
		return ;
	y = 0;
	while (arr[y])
	{
		free(arr[y]);
		y++;
	}
	free(arr);
}
