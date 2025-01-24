/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:10 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/24 17:48:43 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_input(int keycode, t_vars *vars)
{
	if (!vars->map.end)
	{
		move_farmer(vars, keycode);
		redraw_window(vars);
		ft_printf("\rMovements: %d   carrots: %d   ",
			vars->farmer.mov_count, vars->map.c);
	}
	if (keycode == ESC)
	{
		cleanup(vars);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	cleacleanup_images(t_vars *vars)
{
	if (vars->farmer.front)
		mlx_destroy_image(vars->mlx, vars->farmer.front);
	if (vars->farmer.start)
		mlx_destroy_image(vars->mlx, vars->farmer.start);
	if (vars->ground.img)
		mlx_destroy_image(vars->mlx, vars->ground.img);
	if (vars->wall.img)
		mlx_destroy_image(vars->mlx, vars->wall.img);
	if (vars->carrot.img)
		mlx_destroy_image(vars->mlx, vars->carrot.img);
	if (vars->house.img)
		mlx_destroy_image(vars->mlx, vars->house.img);
	if (vars->pig.img)
		mlx_destroy_image(vars->mlx, vars->pig.img);
}

void	cleanup(t_vars *vars)
{
	if (vars->map.arr)
		free_map(vars->map.arr);
	if (vars->farmer.front)
		mlx_destroy_image(vars->mlx, vars->farmer.front);
	if (vars->farmer.start)
		mlx_destroy_image(vars->mlx, vars->farmer.start);
	if (vars->ground.img)
		mlx_destroy_image(vars->mlx, vars->ground.img);
	if (vars->wall.img)
		mlx_destroy_image(vars->mlx, vars->wall.img);
	if (vars->carrot.img)
		mlx_destroy_image(vars->mlx, vars->carrot.img);
	if (vars->house.img)
		mlx_destroy_image(vars->mlx, vars->house.img);
	if (vars->pig.img)
		mlx_destroy_image(vars->mlx, vars->pig.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
		return (error_message("Invalid argument. Please add a valid map path"));
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	init_map(&vars, av[1]);
	vars.win = mlx_new_window(vars.mlx, vars.map.width,
			vars.map.height, "So_long");
	if (!vars.win)
		return (free(vars.mlx), 1);
	init_img(&vars);
	redraw_window(&vars);
	mlx_key_hook(vars.win, handle_input, &vars);
	mlx_loop(vars.mlx);
	cleanup(&vars);
}
