#include "mlx/mlx.h"
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

// COMP MAC: cc main.c ./mlx/libmlx.a -framework OpenGL -framework AppKit

int	main()
{
	void 	*mlx_connection;
	void	*mlx_window;
	int		y;
	int		x;

	srand(time(NULL));
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "my 1st window");
	y = (HEIGHT * 0.1);
	while (++y < (HEIGHT * 0.9))
	{
		x = (WIDTH * 0.1);
		while (++x < (WIDTH * 0.9))
			mlx_pixel_put(mlx_clear_window, mlx_window, x , y, rand() % 0x1000000);
	}
	mlx_string_put(mlx_connection,
				mlx_window,
				WIDTH * 0.8,
				HEIGHT * 0.95,
				rand() % 0x1000000,
				"ggalizon");

	mlx_loop(mlx_connection);
}
