#include "so_long.h"
#include <stdio.h> //TEMP


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
	while (vars->map.arr[row]) // Iterate through map rows
	{
		col = 0;
		while (vars->map.arr[row][col]) // Iterate through map columns
		{
			if (vars->map.arr[row][col] == '1') // Check for wall in the map
			{
				x = col * TILE_SIZE; // Calculate screen X position
				y = row * TILE_SIZE; // Calculate screen Y position
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x, y);
			}
			col++;
		}
		row++;
	}
}


void	redraw_window(t_vars *vars, int farmer_x, int farmer_y)
{
	mlx_clear_window(vars->mlx, vars->win);
	tile_window(vars);
	draw_layer(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->farmer.img, farmer_x, farmer_y);
}

int	handle_input(int keycode, t_vars *vars)
{
	static int farmer_x = 0;
	static int farmer_y = 0;

	// MacOS keys

	if (keycode == 124) // Right arrow
		farmer_x += TILE_SIZE;
	if (keycode == 123) // Left arrow
		farmer_x -= TILE_SIZE;
	if (keycode == 126) // Up arrow
		farmer_y -= TILE_SIZE;
	if (keycode == 125) // Down arrow
		farmer_y += TILE_SIZE;


	// Linux keys
	// if (keycode == 65363) // Right arrow
	// 	farmer_x += TILE_SIZE;
	// if (keycode == 65361) // Left arrow
	// 	farmer_x -= TILE_SIZE;
	// if (keycode == 65362) // Up arrow
	// 	farmer_y -= TILE_SIZE;
	// if (keycode == 65364) // Down arrow
	// 	farmer_y += TILE_SIZE;
	// printf("Farmer position: x=%d, y=%d\n", farmer_x, farmer_y);

	redraw_window(vars, farmer_x, farmer_y);

	if (keycode  == 53) //65307 linux
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

int	main(int ac, char **av)
{
	if (ac != 2) // melhorar isso aqui depois
		return 1;
	t_vars	vars;
	int	img_width, img_height;
	int	tile_width, tile_height;

	printf("%s\n", av[1]);

	vars.map.arr = make_map_arr(av[1]);
	vars.width = (ft_strlen(vars.map.arr[0]) - 1) * TILE_SIZE; //ver se tem uma solucao melhor pra isso
	vars.height = ft_arrlen(vars.map.arr) * TILE_SIZE;

	vars.mlx = mlx_init();
		if(!vars.mlx)
			return (1);
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "So_long");
	if (!vars.win)
		return (free(vars.mlx), 1);

	// if not return
	vars.ground.img = mlx_xpm_file_to_image(vars.mlx, GROUND, &img_width, &img_height);
	vars.wall.img = mlx_xpm_file_to_image(vars.mlx, WALL, &tile_width, &tile_height);
	vars.farmer.img = mlx_xpm_file_to_image(vars.mlx, FARMER, &img_width, &img_height);

	redraw_window(&vars, 0, 0);

	// mlx_hook(vars.win, 2, 1L << 0, handle_input, &vars); // macOS
	mlx_key_hook(vars.win, handle_input, &vars); // linux

	mlx_loop(vars.mlx);

	//Cleanup
	mlx_destroy_window(vars.mlx, vars.win);
	free(vars.mlx);
}
