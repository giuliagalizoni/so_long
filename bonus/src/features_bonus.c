/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:06:40 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/28 17:23:54 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_movcount(t_vars *vars)
{
	char	*mov_count_str;
	char	*str_to_show;

	mov_count_str = ft_itoa(vars->farmer.mov_count);
	str_to_show = ft_strjoin("Movements: ", mov_count_str);
	if (vars->map.width <= 300)
	{
		mlx_string_put(vars->mlx, vars->win,
			vars->map.width * 0.01, vars->map.height * 0.05,
			0xffffff, str_to_show);
	}
	else
	{
		mlx_string_put(vars->mlx, vars->win,
			vars->map.width * 0.85, vars->map.height * 0.05,
			0xffffff, str_to_show);
	}
	free(mov_count_str);
	free(str_to_show);
}

void	toggle_img(void *img1, void *img2, void **image_to_display)
{
	if (*image_to_display == img1)
		*image_to_display = img2;
	else
		*image_to_display = img1;
}

void	farmer_animation(t_vars *vars, int keycode)
{
	static void	*image_to_display;

	if (keycode == LEFT)
	{
		if (!image_to_display)
			image_to_display = vars->farmer.left_1;
		toggle_img(vars->farmer.left_1, vars->farmer.left_2, &image_to_display);
		mlx_put_image_to_window(vars->mlx, vars->win, image_to_display,
			vars->farmer.x, vars->farmer.y);
	}
	if (keycode == RIGHT)
	{
		if (!image_to_display)
			image_to_display = vars->farmer.right_1;
		toggle_img(vars->farmer.right_1, vars->farmer.right_2, &image_to_display);
		mlx_put_image_to_window(vars->mlx, vars->win, image_to_display,
			vars->farmer.x, vars->farmer.y);
	}
	if (keycode == UP)
	{
		if (!image_to_display)
			image_to_display = vars->farmer.back_1;
		toggle_img(vars->farmer.back_1, vars->farmer.back_2, &image_to_display);
		mlx_put_image_to_window(vars->mlx, vars->win, image_to_display,
			vars->farmer.x, vars->farmer.y);
	}
	if (keycode == DOWN)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->farmer.front,
			vars->farmer.x, vars->farmer.y);
	}
}
