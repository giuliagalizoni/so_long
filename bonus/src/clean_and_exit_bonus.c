/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:04:01 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/28 14:04:24 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	exit_sucess(t_vars *vars)
{
	cleanup(vars);
	exit(EXIT_SUCCESS);
	return (1);
}

int	error_message(char *message)
{
	ft_printf(message);
	exit(EXIT_FAILURE);
	return (1);
}

void	free_map(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

static void	cleanup_images(t_vars *vars)
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

	cleanup_images(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}
