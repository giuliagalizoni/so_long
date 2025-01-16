#include "so_long.h"
#include <stdio.h> //TEMP

	char	*map_arr[] = { "11111111111",
						"10000000001",
						"10000100001",
						"10000111111",
						"10000000001",
						"10000000001",
						"10000000001",
						"11111111111", 0 };

void	tile_window(t_vars vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.ground.img, x, y);
			x += TILE_SIZE; // Move to the next tile horizontally
		}
		y += TILE_SIZE; // Move to the next row of tiles
	}
}

void	draw_layer(t_vars vars)
{
	int	x;
	int	y;
	int	row;
	int	col;

	// char	*map_arr[] = { "1111111111",
	// 					"1000000001",
	// 					"1000000001",
	// 					"1000000001",
	// 					"1000000001",
	// 					"1000000001",
	// 					"1000000001",
	// 					"1111111111", 0 };

	row = 0;
	while (map_arr[row]) // Iterate through map rows
	{
		col = 0;
		while (map_arr[row][col]) // Iterate through map columns
		{
			if (map_arr[row][col] == '1') // Check for wall in the map
			{
				x = col * TILE_SIZE; // Calculate screen X position
				y = row * TILE_SIZE; // Calculate screen Y position
				mlx_put_image_to_window(vars.mlx, vars.win, vars.wall.img, x, y);
			}
			col++;
		}
		row++;
	}
}


void	redraw_window(t_vars *vars, int farmer_x, int farmer_y)
{
	mlx_clear_window(vars->mlx, vars->win);
	tile_window(*vars);
	draw_layer(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->farmer.img, farmer_x, farmer_y);
}

int	handle_input(int keycode, t_vars *vars)
{
	static int farmer_x = 0;
	static int farmer_y = 0;

	// MacOS keys
	/*
	if (keycode == 124) // Right arrow
		farmer_x += TILE_SIZE;
	if (keycode == 123) // Left arrow
		farmer_x -= TILE_SIZE;
	if (keycode == 126) // Up arrow
		farmer_y -= TILE_SIZE;
	if (keycode == 125) // Down arrow
		farmer_y += TILE_SIZE;
	*/

	// Linux keys
	if (keycode == 65363) // Right arrow
		farmer_x += TILE_SIZE;
	if (keycode == 65361) // Left arrow
		farmer_x -= TILE_SIZE;
	if (keycode == 65362) // Up arrow
		farmer_y -= TILE_SIZE;
	if (keycode == 65364) // Down arrow
		farmer_y += TILE_SIZE;
	printf("Farmer position: x=%d, y=%d\n", farmer_x, farmer_y);

	redraw_window(vars, farmer_x, farmer_y);

	if (keycode  == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(1);
	}
	return (0);
}

int ft_arrlen(char **array)
{
	int count;
	count = 0;

 	while (array[count])
 		count++;
	return count;
}

int	main(void)
{
	t_vars	vars;
	int	img_width, img_height;
	int	tile_width, tile_height;
	int	window_width, window_height;

	// char	*map_arr[] = { "1111111111",
	// 					"1000000001",
	// 					"1000000001",
	// 					"1000000001",
	// 					"1000000001",
	// 					"1000000001",
	// 					"1000000001",
	// 					"1111111111", 0 };


	window_width = ft_strlen(map_arr[0]) * TILE_SIZE;
	printf("window width: %d\n", window_width);
	window_height = ft_arrlen(map_arr) * TILE_SIZE;
	printf("window height: %d\n", window_height);


	vars.mlx = mlx_init();
		if(!vars.mlx)
			return (1);
	vars.win = mlx_new_window(vars.mlx, window_width, window_height, "So_long");
	if (!vars.win)
		return (free(vars.mlx), 1);

	vars.ground.img = mlx_xpm_file_to_image(vars.mlx, GROUND, &img_width, &img_height);
	vars.wall.img = mlx_xpm_file_to_image(vars.mlx, WALL, &tile_width, &tile_height);
	vars.farmer.img = mlx_xpm_file_to_image(vars.mlx, FARMER, &img_width, &img_height);

	redraw_window(&vars, 0, 0);
	// tile_window(vars.mlx, vars.win, &ground, img_width, img_height);
	// draw_layer(vars.mlx, vars.win, &wall, TILE_SIZE, TILE_SIZE, 0, 0, WIDTH, 48);

	// mlx_hook(vars.win, 2, 1L << 0, handle_input, &vars); // macOS
	mlx_key_hook(vars.win, handle_input, &vars); // linux

	mlx_loop(vars.mlx);

	//Cleanup
	mlx_destroy_window(vars.mlx, vars.win);
	free(vars.mlx);
}
