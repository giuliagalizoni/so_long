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

void	farmer_animation(t_vars *vars, int keycode)
{
	if (keycode == LEFT)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->farmer.left,
		vars->farmer.x, vars->farmer.y);
	}
}
