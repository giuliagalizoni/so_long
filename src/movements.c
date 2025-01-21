#include "../so_long.h"

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

void	move_farmer(t_vars *vars, int key)
{
	int	x = vars->farmer.x / TILE_SIZE;
	int	y = vars->farmer.y / TILE_SIZE;

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
}
