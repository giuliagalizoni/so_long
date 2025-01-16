
#include "so_long.h"
#include <stdio.h> //TEMP

void	tile_window(void *mlx, void *win, t_img *img, int tile_width, int tile_height)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_image_to_window(mlx, win, img->img, x, y);
			x += tile_width; // Move to the next tile horizontally
		}
		y += tile_height; // Move to the next row of tiles
	}
}

void	draw_layer(void *mlx, void *win, t_img *tile, int tile_width, int tile_height, int start_x, int start_y, int end_x, int end_y)
{
	int	x;
	int	y;

	y = start_y;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x)
		{
			mlx_put_image_to_window(mlx, win, tile->img, x , y);
			x += tile_width; // Move to the next tile horizontally
		}
		y += tile_height; // Move to the next tile vertically
	}
}

void	put_farmer(t_vars *vars, int key)
{
	t_img farmer;
	int		img_width, img_height;
	static int x;
	static int y;

	farmer.img = mlx_xpm_file_to_image(vars->mlx, FARMER, &img_height, &img_width);

	if (key == 124)
		x += TILE_SIZE;
	if (key == 123)
		x -= TILE_SIZE;
	if (key == 126)
		y -= TILE_SIZE;
	if (key == 125)
		y += TILE_SIZE;
	printf("x: %d y: %d\n", x, y);
	mlx_put_image_to_window(vars->mlx, vars->win, farmer.img, x , y);
}

void	redraw_window(t_vars *vars, t_img *ground, t_img *wall, t_img *farmer, int farmer_x, int farmer_y)
{
	mlx_clear_window(vars->mlx, vars->win);
	tile_window(vars->mlx, vars->win, ground, TILE_SIZE, TILE_SIZE);
	draw_layer(vars->mlx, vars->win, wall, TILE_SIZE, TILE_SIZE, 0, 0, WIDTH, 48);
	mlx_put_image_to_window(vars->mlx, vars->win, farmer->img, farmer_x, farmer_y);
}

int	handle_input(int keycode, t_vars *vars)
{
	static int farmer_x = 0;
	static int farmer_y = 0;

	if (keycode == 124) // Right arrow
		farmer_x += TILE_SIZE;
	if (keycode == 123) // Left arrow
		farmer_x -= TILE_SIZE;
	if (keycode == 126) // Up arrow
		farmer_y -= TILE_SIZE;
	if (keycode == 125) // Down arrow
		farmer_y += TILE_SIZE;

	printf("Farmer position: x=%d, y=%d\n", farmer_x, farmer_y);

	redraw_window(vars, &vars->ground, &vars->wall, &vars->farmer, farmer_x, farmer_y);

	if (keycode  == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(1);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		img_width, img_height;
	int		tile_width, tile_height;

	vars.mlx = mlx_init();
		if(!vars.mlx)
			return (1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "So_long");
	if (!vars.win)
		return (free(vars.mlx), 1);


	vars.ground.img = mlx_xpm_file_to_image(vars.mlx, GROUND, &img_width, &img_height);
	vars.wall.img = mlx_xpm_file_to_image(vars.mlx, WALL, &tile_width, &tile_height);
	vars.farmer.img = mlx_xpm_file_to_image(vars.mlx, FARMER, &img_width, &img_height);

	redraw_window(&vars, &vars.ground, &vars.wall, &vars.farmer, 0, 0);
	// tile_window(vars.mlx, vars.win, &ground, img_width, img_height);
	// draw_layer(vars.mlx, vars.win, &wall, TILE_SIZE, TILE_SIZE, 0, 0, WIDTH, 48);

	mlx_hook(vars.win, 2, 1L << 0, handle_input, &vars);
	// mlx_key_hook(vars.win, handle_input, &vars); // test this on linux

	mlx_loop(vars.mlx);

	//Cleanup
	mlx_destroy_window(vars.mlx, vars.win);
	free(vars.mlx);
}
