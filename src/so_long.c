/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:10 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/17 18:31:33 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_start_position(t_vars *vars)
{
	int	row;
	int	col;

	row = 0;
	while (vars->map.arr[row])
	{
		col = 0;
		while (vars->map.arr[row][col])
		{
			if (vars->map.arr[row][col] == 'P')
			{
				vars->farmer.x = col * TILE_SIZE;
				vars->farmer.y = row * TILE_SIZE;
				return ;
			}
			col++;
		}
		row++;
	}
}

int	handle_input(int keycode, t_vars *vars)
{
	if (keycode == UP)
		vars->farmer.y -= TILE_SIZE;
	if (keycode == DOWN)
		vars->farmer.y += TILE_SIZE;
	if (keycode == RIGHT)
		vars->farmer.x += TILE_SIZE;
	if (keycode == LEFT)
		vars->farmer.x -= TILE_SIZE;
	redraw_window(vars);
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(1);
	}
	return (0);
}

int	ft_arrlen(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2) // melhorar isso aqui depois
	{
		ft_printf("Invalid argument. Please add a valid map path");
		return (1);
	}
	vars.map.arr = make_map_arr(av[1]);
	vars.width = (ft_strlen(vars.map.arr[0]) - 1) * TILE_SIZE;
	//ver se tem uma solucao melhor pra isso
	vars.height = ft_arrlen(vars.map.arr) * TILE_SIZE;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "So_long");
	if (!vars.win)
		return (free(vars.mlx), 1);
	init_img(&vars);
	find_start_position(&vars);
	redraw_window(&vars);
	// mlx_hook(vars.win, 2, 1L << 0, handle_input, &vars); // macOS
	mlx_key_hook(vars.win, handle_input, &vars); // linux
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	free(vars.mlx);
}
