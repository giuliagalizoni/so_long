#include "../so_long_bonus.h"

void	init_farmer(t_vars *vars, int *img_width, int *img_height)
{
	vars->farmer.front = mlx_xpm_file_to_image(vars->mlx, FARMER,
			img_width, img_height);
	if (!vars->farmer.front)
	{
		cleanup(vars);
		error_message("Error loading farmer image");
	}
	vars->farmer.start = mlx_xpm_file_to_image(vars->mlx, FARMER_START,
			img_width, img_height);
	if (!vars->farmer.start)
	{
		cleanup(vars);
		error_message("Error loading farmer start image");
	}
}

void	init_elements(t_vars *vars, int *img_width, int *img_height)
{
	vars->carrot.img = mlx_xpm_file_to_image(vars->mlx, CARROT,
			img_width, img_height);
	if (!vars->carrot.img)
	{
		cleanup(vars);
		error_message("Error loading carrot image");
	}
	vars->house.img = mlx_xpm_file_to_image(vars->mlx, HOUSE,
			img_width, img_height);
	if (!vars->house.img)
	{
		cleanup(vars);
		error_message("Error loading house image");
	}
	vars->pig.img = mlx_xpm_file_to_image(vars->mlx, PIG,
			img_width, img_height);
	if (!vars->pig.img)
	{
		cleanup(vars);
		error_message("Error loading pig image");
	}
}

void	init_img(t_vars *vars)
{
	int	img_width;
	int	img_height;
	int	tile_width;
	int	tile_height;

	vars->ground.img = mlx_xpm_file_to_image(vars->mlx, GROUND,
			&img_width, &img_height);
	if (!vars->ground.img)
	{
		cleanup(vars);
		error_message("Error loading ground image");
	}
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, WALL,
			&tile_width, &tile_height);
	if (!vars->wall.img)
	{
		cleanup(vars);
		error_message("Error loading wall image");
	}
	init_farmer(vars, &img_width, &img_height);
	init_elements(vars, &img_width, &img_height);
}
