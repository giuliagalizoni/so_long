#include "so_long.h"

#include <stdio.h> //Temporary

#define MALLOC_ERROR	1
#define	SIDE_LEN		800
#define X				50
#define Y				50

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
} t_img;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_var;

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));

	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

/*
 * 🔥 my_pixel_put
*/
void	color_screen(t_var *data, int color)
{
			my_pixel_put(&data->img,
						X,
						Y,
						color);
}


int	f(int keysym, t_var *data)
{

	if (keysym == XK_r)
	{
		color_screen(data, 0xff0000);
	}
	else if (keysym == XK_g)
	{
		color_screen(data, 0xff00);
	}
	else if (keysym == XK_b)
	{
		color_screen(data, 0xff);
	}
	else if (keysym == XK_Escape)
		exit(1);

	// push the READY image to window
	// the last parameters are the offset image-window
	mlx_put_image_to_window(data->mlx,
							data->win,
							data->img.img_ptr,
							0, 0);

	return 0;
}

int	main(void)
{
		t_var	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,
								SIDE_LEN,
								SIDE_LEN,
								"My window");


	// Code to create an image and get the related DATA
	vars.img.img_ptr = mlx_new_image(vars.mlx,
									SIDE_LEN,
									SIDE_LEN);
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr,
												&vars.img.bits_per_pixel,
												&vars.img.line_len,
												&vars.img.endian);


	printf("Line_len %d <-> SIDE_LEN %d\n"
			"bpp %d\n"
			"endian %d\n", vars.img.line_len, SIDE_LEN, vars.img.bits_per_pixel, vars.img.endian);

	mlx_key_hook(vars.win,
				f,
				&vars);
	mlx_loop(vars.mlx);
	// t_var vars;

	// vars.mlx = mlx_init();
	// if (!vars.mlx)
	// 	return (MALLOC_ERROR);

	// vars.win = mlx_new_window(vars.mlx, SIDE_LEN, SIDE_LEN, "window");
	// if (!vars.win)
	// {
	// 	mlx_destroy_display(vars.mlx);
	// 	free(vars.mlx);
	// 	return (MALLOC_ERROR);
	// }

	// vars.img.img_ptr = mlx_new_image(vars.mlx, SIDE_LEN, SIDE_LEN);
	// vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_pixels_ptr, &vars.img.bits_per_pixel, &vars.img.line_len, &vars.img.endian);

	// mlx_key_hook(vars.win, f, &vars);
	// mlx_loop(vars.mlx);
	// return 0;
}


// int	handle_input(int keysym, t_mlx_data *data)
// {
// 	//keysym lib
// 	//keycode is tied to the keybord, while keysym is tied to the symbole - and therefore more portable
// 	if (keysym == XK_Escape)
// 	{
// 		printf("The %d key (ESC) has been pressed\n", keysym);
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		mlx_destroy_display(data->mlx_ptr);
// 		free(data->mlx_ptr);
// 		exit(1);
// 	}
// 	printf("The %d key has been pressed\n\n", keysym);
// 	return (0);
// }

	// #define MALLOC_ERROR	1
	// #define WIDTH	400
	// #define HEIGHT	400

	// void	*mlx_connection;// store the pointer to the struct that cointains mlx connection info
	// void	*mlx_window; //store the ptr to the window

	// mlx_connection = mlx_init();
	// if (!mlx_connection)
	// 	return (MALLOC_ERROR);

	// mlx_window = mlx_new_window(mlx_connection, HEIGHT, WIDTH, "My window"); //init the window

	// if (!mlx_window) //check for malloc errors
	// {
	// 	mlx_destroy_display(mlx_connection);
	// 	free(mlx_connection);
	// 	return (MALLOC_ERROR);
	// }

	// mlx_loop(mlx_connection); //event loop so the program can keep working and listening for events


	// mlx_destroy_display(mlx_connection); //cleanup function to clean what was allocated
	// free(mlx_connection); //free our variable as well


