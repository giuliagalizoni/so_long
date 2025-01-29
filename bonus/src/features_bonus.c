/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:06:40 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/29 20:00:53 by giuliagaliz      ###   ########.fr       */
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

void	toggle_img(void *img1, void *img2, void **img_to_display)
{

	if (*img_to_display == img1)
		*img_to_display = img2;
	else
		*img_to_display = img1;

}

void	move_sides(t_vars *vars, int keycode, void **img_to_display)
{
	if (keycode == LEFT)
	{
		// if (!*img_to_display)
			*img_to_display = vars->farmer.left_1;
		// toggle_img(vars->farmer.left_1, vars->farmer.left_2, img_to_display);
		mlx_put_image_to_window(vars->mlx, vars->win, *img_to_display,
			vars->farmer.x, vars->farmer.y);
	}
	if (keycode == RIGHT)
	{
		// if (!*img_to_display)
			*img_to_display = vars->farmer.right_1;
		// toggle_img(vars->farmer.right_1, vars->farmer.right_2, img_to_display);
		mlx_put_image_to_window(vars->mlx, vars->win, *img_to_display,
			vars->farmer.x, vars->farmer.y);
	}
}

void	move_updown(t_vars *vars, int keycode, void **img_to_display)
{
	if (keycode == UP)
	{
		// if (!*img_to_display)
			*img_to_display = vars->farmer.back_1;
		// toggle_img(vars->farmer.back_1, vars->farmer.back_2, img_to_display);
		mlx_put_image_to_window(vars->mlx, vars->win, *img_to_display,
			vars->farmer.x, vars->farmer.y);
	}
	if (keycode == DOWN)
	{
		// if (!*img_to_display)
			*img_to_display = vars->farmer.front_1;
		// toggle_img(vars->farmer.front_1, vars->farmer.front_2, img_to_display);
		mlx_put_image_to_window(vars->mlx, vars->win, *img_to_display,
			vars->farmer.x, vars->farmer.y);
	}
}
void	farmer_animation(t_vars *vars, int keycode)
{
	static void	*image_to_display;

	if (keycode == LEFT || keycode == RIGHT)
		move_sides(vars, keycode, &image_to_display);
	if (keycode == UP || keycode == DOWN)
		move_updown(vars, keycode, &image_to_display);
}
