/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:08:08 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/29 22:04:30 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_farmer(t_vars *vars, int *img_width, int *img_height)
{
	// vars->farmer.front = mlx_xpm_file_to_image(vars->mlx, FARMER,
	// 		img_width, img_height);
	// if (!vars->farmer.front)
	// {
	// 	cleanup(vars);
	// 	error_message("Error loading farmer image");
	// }
	vars->farmer.start = mlx_xpm_file_to_image(vars->mlx, FARMER_START,
			img_width, img_height);
	if (!vars->farmer.start)
	{
		cleanup(vars);
		error_message("Error loading farmer start image");
	}
}

void	init_farmer_anim1(t_vars *vars, int *img_width, int *img_height)
{
	vars->farmer.right_1 = mlx_xpm_file_to_image(vars->mlx, FARMER_RIGHT_1,
			img_width, img_height);
	if (!vars->farmer.right_1)
	{
		cleanup(vars);
		error_message("Error loading farmer right 1 image");
	}
	vars->farmer.left_1 = mlx_xpm_file_to_image(vars->mlx, FARMER_LEFT_1,
			img_width, img_height);
	if (!vars->farmer.left_1)
	{
		cleanup(vars);
		error_message("Error loading farmer left 1 image");
	}
	vars->farmer.back_1 = mlx_xpm_file_to_image(vars->mlx, FARMER_BACK_1,
			img_width, img_height);
	if (!vars->farmer.back_1)
	{
		cleanup(vars);
		error_message("Error loading farmer back 1 image");
	}
	vars->farmer.front_1 = mlx_xpm_file_to_image(vars->mlx, FARMER_FRONT_1,
			img_width, img_height);
	if (!vars->farmer.front_1)
	{
		cleanup(vars);
		error_message("Error loading farmer front 1 image");
	}
}

void	init_farmer_anim2(t_vars *vars, int *img_width, int *img_height)
{
	vars->farmer.right_2 = mlx_xpm_file_to_image(vars->mlx, FARMER_RIGHT_2,
			img_width, img_height);
	if (!vars->farmer.right_2)
	{
		cleanup(vars);
		error_message("Error loading farmer right 2 image");
	}
	vars->farmer.left_2 = mlx_xpm_file_to_image(vars->mlx, FARMER_LEFT_2,
			img_width, img_height);
	if (!vars->farmer.left_2)
	{
		cleanup(vars);
		error_message("Error loading farmer left 2 image");
	}
	vars->farmer.back_2 = mlx_xpm_file_to_image(vars->mlx, FARMER_BACK_2,
			img_width, img_height);
	if (!vars->farmer.back_2)
	{
		cleanup(vars);
		error_message("Error loading farmer back 2 image");
	}
	vars->farmer.front_2 = mlx_xpm_file_to_image(vars->mlx, FARMER_FRONT_2,
			img_width, img_height);
	if (!vars->farmer.front_2)
	{
		cleanup(vars);
		error_message("Error loading farmer front 2 image");
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
	vars->monster_img = mlx_xpm_file_to_image(vars->mlx, MONSTER, &tile_width, &tile_height);
	if (!vars->monster_img)
	{
		cleanup(vars);
		error_message("Error loading wall image");
	}
	init_farmer(vars, &img_width, &img_height);
	init_elements(vars, &img_width, &img_height);
	init_farmer_anim1(vars, &img_width, &img_height);
	init_farmer_anim2(vars, &img_width, &img_height);
}
