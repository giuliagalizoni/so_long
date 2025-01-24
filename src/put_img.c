/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:59:44 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/24 17:03:46 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_img(t_vars *vars)
{
	int	img_width;
	int	img_height;
	int	tile_width;
	int	tile_height;

	vars->ground.img = mlx_xpm_file_to_image(vars->mlx, GROUND,
			&img_width, &img_height);
	if (!vars->ground.img)
		cleanup(vars);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, WALL,
			&tile_width, &tile_height);
	if (!vars->wall.img)
		cleanup(vars);
	vars->farmer.front = mlx_xpm_file_to_image(vars->mlx, FARMER,
			&img_width, &img_height);
	if (!vars->farmer.front)
		cleanup(vars);
	vars->carrot.img = mlx_xpm_file_to_image(vars->mlx, CARROT,
			&img_width, &img_height);
	if (!vars->carrot.img)
		cleanup(vars);
	vars->house.img = mlx_xpm_file_to_image(vars->mlx, HOUSE,
			&img_width, &img_height);
	if (!vars->house.img)
		cleanup(vars);
	vars->farmer.start = mlx_xpm_file_to_image(vars->mlx, FARMER_START,
			&img_width, &img_height);
	if (!vars->farmer.start)
		cleanup(vars);
	vars->pig.img = mlx_xpm_file_to_image(vars->mlx, PIG,
			&img_width, &img_height);
	if (!vars->pig.img)
		cleanup(vars);
}

// void	tile_window(t_vars *vars)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < vars->map.height)
// 	{
// 		x = 0;
// 		while (x < vars->map.width)
// 		{
// 			mlx_put_image_to_window(vars->mlx, vars->win,
// 				vars->ground.img, x, y);
// 			x += TILE_SIZE;
// 		}
// 		y += TILE_SIZE;
// 	}
// }

void	check_tile(t_vars *vars, int row, int col)
{
	int	x;
	int	y;

	x = col * TILE_SIZE;
	y = row * TILE_SIZE;
	if (vars->map.arr[row][col] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ground.img, x, y);
	if (vars->map.arr[row][col] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x, y);
	else if (vars->map.arr[row][col] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->carrot.img, x, y);
	else if (vars->map.arr[row][col] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->house.img, x, y);
	else if (vars->map.arr[row][col] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->pig.img, x, y);
}

void	draw_layer(t_vars *vars)
{
	int	row;
	int	col;

	row = 0;
	while (vars->map.arr[row])
	{
		col = 0;
		while (vars->map.arr[row][col])
		{
			check_tile(vars, row, col);
			col++;
		}
		row++;
	}
}

void	put_credits(t_vars *vars)
{
	if (vars->map.width <= 300)
	{
		mlx_string_put(vars->mlx, vars->win,
			vars->map.width * 0.01, vars->map.height * 0.93,
			0xadf78d, "developed with <3 by ggalizon *");
		mlx_string_put(vars->mlx, vars->win,
			vars->map.width * 0.01, vars->map.height * 0.98,
			0xadf78d, "assets by: Kenmi");
	}
	else
	{
		mlx_string_put(vars->mlx, vars->win,
			vars->map.width * 0.01, vars->map.height * 0.98,
			0xadf78d, "developed with <3 by ggalizon * assets by: Kenmi");
	}
}

void	end_game(t_vars *vars)
{
	int	center_x;
	int	center_y;

	// tile_window(vars);
	center_x = vars->map.width / 2;
	center_y = vars->map.height / 2;
	mlx_string_put(vars->mlx, vars->win, center_x - 50, center_y - 10,
		0xFFFFFF, "YOU WIN!!!");
	mlx_string_put(vars->mlx, vars->win, center_x - 75, center_y + 20,
		0xFFFFFF, "Press ESC to exit");
	vars->map.end = 1;
}

void	redraw_window(t_vars *vars)
{
	int	y;
	int	x;

	y = vars->farmer.y / TILE_SIZE;
	x = vars->farmer.x / TILE_SIZE;
	mlx_clear_window(vars->mlx, vars->win);
	// tile_window(vars);
	draw_layer(vars);
	put_credits(vars);
	if (vars->map.arr[y][x] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->farmer.start, vars->farmer.x, vars->farmer.y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->farmer.front, vars->farmer.x, vars->farmer.y);
	if (vars->map.arr[y][x] == 'C')
	{
		vars->map.arr[y][x] = '0';
		vars->map.c--;
	}
	if (vars->map.c == 0 && vars->map.arr[y][x] == 'E')
	{
		end_game(vars);
		return ;
	}
}
