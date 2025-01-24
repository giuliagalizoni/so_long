/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:26:55 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/24 18:32:40 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error_message(char *message)
{
	ft_printf(message);
	exit(EXIT_FAILURE);
	return (1);
}

int	check_horizontal_border(char **map, int width, int row)
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

int	check_vertical_border(char **map, int height, int col)
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

int	check_borders(t_vars *vars)
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

int	check_map(t_vars *vars)
{
	int		y;
	size_t	first_len;

	first_len = ft_strlen(vars->map.arr[0]);
	y = 0;
	while (vars->map.arr[y])
	{
		if (ft_strlen(vars->map.arr[y]) != first_len)
		{
			cleanup(vars);
			return (error_message("Invalid map. Please select a rectangular map"));
		}
		y++;
	}
	if (check_borders(vars))
	{
		cleanup(vars);
		return (error_message("There's a whole in your map"));
	}
	return (0);
}
