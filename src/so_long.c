/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:10 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/20 14:03:36 by giuliagaliz      ###   ########.fr       */
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
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		free(vars->map.arr);
		exit(1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2) // melhorar isso aqui depois
	{
		ft_printf("Invalid argument. Please add a valid map path");
		return (1);
	}
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
	// mlx_hook(vars.win, 2, 1L << 0, handle_input, &vars); // macOS
	mlx_key_hook(vars.win, handle_input, &vars); // linux
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	free(vars.mlx);
}
