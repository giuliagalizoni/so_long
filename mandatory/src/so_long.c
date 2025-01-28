/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:10 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/28 12:07:58 by ggalizon         ###   ########.fr       */
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
		exit_sucess(vars);
	return (0);
}

static int	check_map_path(char *map_path)
{
	int	len;

	len = ft_strlen(map_path);
	if (len <= 4)
		return (error_message("Invalid map path"), 0);
	if (!ft_strnstr(map_path, ".ber", len))
		return (error_message("Invalid path. Map should be a .ber file"), 0);
	if (map_path[len - 4] != '.')
		return (error_message("Invalid path. Map should be a .ber file"), 0);
	if (map_path[len - 3] != 'b')
		return (error_message("Invalid path. Map should be a .ber file"), 0);
	if (map_path[len - 2] != 'e')
		return (error_message("Invalid path. Map should be a .ber file"), 0);
	if (map_path[len - 1] != 'r')
		return (error_message("Invalid path. Map should be a .ber file"), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
		return (error_message("Invalid argument. Please add a valid map path"));
	check_map_path(av[1]);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	init_img(&vars);
	vars.win = NULL;
	init_map(&vars, av[1]);
	vars.win = mlx_new_window(vars.mlx, vars.map.width,
			vars.map.height, "So_long");
	if (!vars.win)
		return (free(vars.mlx), 1);
	redraw_window(&vars);
	mlx_key_hook(vars.win, handle_input, &vars);
	mlx_hook(vars.win, 17, 0, exit_sucess, &vars);
	mlx_loop(vars.mlx);
	cleanup(&vars);
}
