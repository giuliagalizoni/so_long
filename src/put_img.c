/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:59:44 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/17 18:37:33 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_img(t_vars *vars)
{
	int	img_width;
	int	img_height;
	int	tile_width;
	int	tile_height;

	// if not return
	vars->ground.img = mlx_xpm_file_to_image(vars->mlx, GROUND, &img_width, &img_height);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, WALL, &tile_width, &tile_height);
	vars->farmer.front = mlx_xpm_file_to_image(vars->mlx, FARMER, &img_width, &img_height);
	vars->carrot.img = mlx_xpm_file_to_image(vars->mlx, CARROT, &img_width, &img_height);
	vars->house.img = mlx_xpm_file_to_image(vars->mlx, HOUSE, &img_width, &img_height);
	vars->farmer.start = mlx_xpm_file_to_image(vars->mlx, FARMER_START, &img_width, &img_height);
}

void	tile_window(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->ground.img, x, y);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
}

void	draw_layer(t_vars *vars)
{
	int	x;
	int	y;
	int	row;
	int	col;

	row = 0;
	while (vars->map.arr[row])
	{
		col = 0;
		while (vars->map.arr[row][col])
		{
			x = col * TILE_SIZE;
			y = row * TILE_SIZE;
			if (vars->map.arr[row][col] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x, y);
			else if (vars->map.arr[row][col] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->carrot.img, x, y);
			else if (vars->map.arr[row][col] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->house.img, x, y);
			col++;
		}
		row++;
	}
}

void	redraw_window(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	tile_window(vars);
	draw_layer(vars);
	if (vars->map.arr[vars->farmer.y / TILE_SIZE][vars->farmer.x / TILE_SIZE] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->farmer.start, vars->farmer.x, vars->farmer.y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->farmer.front, vars->farmer.x, vars->farmer.y);
}
