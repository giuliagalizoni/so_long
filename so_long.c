#include "mlx/mlx.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	tile_window(void *mlx, void *win, t_data *img, int tile_width, int tile_height)
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

void	draw_layer(void *mlx, void *win, t_data *tile, int tile_width, int tile_height, int start_x, int start_y, int end_x, int end_y)
{
	int	x;
	int	y;

	y = start_y;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x)
		{
			mlx_put_image_to_window(mlx, win, tile->img, x, y);
			x += tile_width; // Move to the next tile horizontally
		}
		y += tile_height; // Move to the next tile vertically
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	wall;
	int		img_width, img_height;
	int		tile_width, tile_height;

	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "So_long");

	img_width = 64; // Default width if loading fails
	img_height = 64; // Default height if loading fails


	img.img = mlx_xpm_file_to_image(mlx, "assets/Grass_Middle.xpm", &img_width, &img_height);

	tile_width = 0;
	tile_height = 0;
	wall.img = mlx_xpm_file_to_image(mlx, "assets/FarmLand_Tile.xpm", &tile_width, &tile_height);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	tile_window(mlx, mlx_win, &img, img_width, img_height);
	draw_layer(mlx, mlx_win, &wall, tile_width, tile_height, 100, 200, 700, 250);
	mlx_loop(mlx);
}
