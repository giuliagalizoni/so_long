/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:26:55 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/28 14:46:39 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_horizontal_border(char **map, int width, int row)
{
	int	x;

	x = 0;
	while (x < width)
	{
		if (map[row][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

static int	check_vertical_border(char **map, int height, int col)
{
	int	y;

	y = 0;
	while (y < height)
	{
		if (map[y][col] != '1')
			return (1);
		y++;
	}
	return (0);
}

static int	check_borders(t_vars *vars)
{
	int	width;
	int	height;

	width = vars->map.width / TILE_SIZE;
	height = vars->map.height / TILE_SIZE;
	if (check_horizontal_border(vars->map.arr, width, 0)
		|| check_horizontal_border(vars->map.arr, width, height - 1))
		return (1);
	if (check_vertical_border(vars->map.arr, height, 0)
		|| check_vertical_border(vars->map.arr, height, width - 1))
		return (1);
	return (0);
}

void	check_screen_size(t_vars *vars)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(vars->mlx, &screen_width, &screen_height);
	if (vars->map.width > screen_width || vars->map.height > screen_height)
	{
		cleanup(vars);
		error_message("This map is way too big for your screen");
	}
}

int	check_map(t_vars *vars)
{
	int		y;
	size_t	first_len;

	first_len = ft_strlen(vars->map.arr[0]);
	if (first_len < 4)
		return (cleanup(vars), error_message("Map too short"));
	if (!vars->map.c)
		return (cleanup(vars), error_message("No carrots for your pig :("));
	if (vars->map.p != 1)
		return (cleanup(vars), error_message("You need 1 (and only 1) house"));
	if (vars->map.invalid)
		return (cleanup(vars), error_message("Something souldn't be there"));
	y = 0;
	while (vars->map.arr[y])
	{
		if (ft_strlen(vars->map.arr[y]) != first_len)
			return (cleanup(vars),
				error_message("Invalid map. Please select a rectangular map"));
		y++;
	}
	check_screen_size(vars);
	if (check_borders(vars))
		return (cleanup(vars), error_message
			("Map validation failed.There's a whole in your map"));
	return (0);
}
