/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:18:48 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/29 22:08:18 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	is_valid_move(t_vars *vars, int x, int y)
{
	if (x < 0 || x >= vars->map.width / TILE_SIZE)
		return (0);
	if (y < 0 || y >= vars->map.height / TILE_SIZE)
		return (0);
	if (vars->map.arr[y][x] == '1')
		return (0);
	return (1);
}
// multiple monsters
int	is_monster_collision(t_vars *vars, int new_x, int new_y)
{
    int i;

    i = 0;
    while (i < vars->monster_count)
    {
        if (vars->monsters[i].x == new_x && vars->monsters[i].y == new_y)
            return (1);
        i++;
    }
    return (0);
}
// single monster
/*int	is_monster_collision(t_vars *vars, int new_x, int new_y)
{
    if (vars->monster.x == new_x && vars->monster.y == new_y)
        return (1);
    return (0);
}*/

void	move_farmer(t_vars *vars, int key)
{
    int	x;
    int	y;

    y = vars->farmer.y / TILE_SIZE;
    x = vars->farmer.x / TILE_SIZE;
    if (key == UP && is_valid_move(vars, x, y - 1))
    {
        if (is_monster_collision(vars, x, y - 1))
            return game_over(vars);
        vars->farmer.y -= TILE_SIZE;
        vars->farmer.mov_count++;
    }
    else if (key == DOWN && is_valid_move(vars, x, y + 1))
    {
        if (is_monster_collision(vars, x, y + 1))
            return game_over(vars);
        vars->farmer.y += TILE_SIZE;
        vars->farmer.mov_count++;
    }
    else if (key == RIGHT && is_valid_move(vars, x + 1, y))
    {
        if (is_monster_collision(vars, x + 1, y))
            return game_over(vars);
        vars->farmer.x += TILE_SIZE;
        vars->farmer.mov_count++;
    }
    else if (key == LEFT && is_valid_move(vars, x - 1, y))
    {
        if (is_monster_collision(vars, x - 1, y))
            return game_over(vars);
        vars->farmer.x -= TILE_SIZE;
        vars->farmer.mov_count++;
    }
}

/*void	move_farmer(t_vars *vars, int key)
{
	int	x;
	int	y;

	y = vars->farmer.y / TILE_SIZE;
	x = vars->farmer.x / TILE_SIZE;
	if (key == UP && is_valid_move(vars, x, y - 1))
	{
		vars->farmer.y -= TILE_SIZE;
		vars->farmer.mov_count++;
	}
	else if (key == DOWN && is_valid_move(vars, x, y + 1))
	{
		vars->farmer.y += TILE_SIZE;
		vars->farmer.mov_count++;
	}
	else if (key == RIGHT && is_valid_move(vars, x + 1, y))
	{
		vars->farmer.x += TILE_SIZE;
		vars->farmer.mov_count++;
	}
	else if (key == LEFT && is_valid_move(vars, x - 1, y))
	{
		vars->farmer.x -= TILE_SIZE;
		vars->farmer.mov_count++;
	}
}*/
