#include "../so_long_bonus.h"

// multiple monsters
void	init_monsters(t_vars *vars)
{
	int	y;
	int	x;
	int	i;

	vars->monster_count = 0;
	y = 0;
	while (y < vars->map.height / TILE_SIZE)
	{
		x = 0;
		while (x < vars->map.width / TILE_SIZE)
		{
			if (vars->map.arr[y][x] == 'M') // Found a monster
				vars->monster_count++;
			x++;
		}
		y++;
	}
	vars->monsters = malloc(sizeof(t_monster) * vars->monster_count);
	if (!vars->monsters)
	{
		cleanup(vars);
		error_message("Memory allocation failed");
	}
	y = 0;
	i = 0;
	while (y < vars->map.height / TILE_SIZE)
	{
		x = 0;
		while (x < vars->map.width / TILE_SIZE)
		{
			if (vars->map.arr[y][x] == 'M') // Found a monster
			{
				vars->monsters[i].x = x;
				vars->monsters[i].y = y;
				vars->monsters[i].direction = 1; // Start moving right
				vars->monsters[i].current_frame = 0;
				vars->monsters[i].timer = 0;
				vars->map.arr[y][x] = '0';
				i++;
			}
			x++;
		}
		y++;
	}
}

int	animate_monsters(t_vars *vars)
{
    int			i;
    t_monster	*monster;

	if (vars->map.end)
        return (0);

    i = 0;
    while (i < vars->monster_count)
    {
        monster = &vars->monsters[i];

        // Increment the timer
        monster->timer++;

        // Check if it's time to update the animation
        if (monster->timer >= ANIMATION_SPEED)
        {
            monster->timer = 0;
            monster->current_frame = !monster->current_frame;

            int next_x = monster->x + monster->direction;
            char next_tile = vars->map.arr[monster->y][next_x];

            // Only move if the next tile is empty
            if (next_tile == '0')
            {
                // Update the map: set current tile to '0' and next tile to 'M'
                vars->map.arr[monster->y][monster->x] = '0';
                vars->map.arr[monster->y][next_x] = 'M';

                // Update the monster's position
                monster->x = next_x;
            }
            else
            {
                // Reverse direction if the move is blocked
                monster->direction *= -1;
            }
			if (monster->x == vars->farmer.x / TILE_SIZE && monster->y == vars->farmer.y / TILE_SIZE)
			{
				game_over(vars);
				return (0);
			}
        }
        i++;
    }

    // Request a redraw
    redraw_window(vars);

    return (0);
}

// one monster
/*void	init_monster(t_vars *vars)
{
	int	y;
	int	x;

	vars->monster.x = -1;
	vars->monster.y = -1;
	y = 0;
	while (y < vars->map.height / TILE_SIZE)
	{
		x = 0;
		while (x < vars->map.width / TILE_SIZE)
		{
			if (vars->map.arr[y][x] == 'M') // Found a monster
			{
				vars->monster.x = x;
				vars->monster.y = y;
				vars->monster.direction = 1; // Start moving right
				vars->monster.current_frame = 0;
				vars->monster.timer = 0;
				vars->map.arr[y][x] = '0';
				break;
			}
			x++;
		}
		y++;
	}
}*/


// one monster
/*int	animate_monster(t_vars *vars)
{
	t_monster *monster;

	 if (vars->map.end)
        return (0);

	monster = &vars->monster;

	// Increment the timer
	monster->timer++;

	// Check if it's time to update the animation
	if (monster->timer >= ANIMATION_SPEED)
	{
		monster->timer = 0;
		monster->current_frame = !monster->current_frame;

		int next_x = monster->x + monster->direction;
		char next_tile = vars->map.arr[monster->y][next_x];

		// Only move if the next tile is empty
		if (next_tile == '0')
		{
			// Update the map: set current tile to '0' and next tile to 'M'
			vars->map.arr[monster->y][monster->x] = '0';
			vars->map.arr[monster->y][next_x] = 'M';

			// Update the monster's position
			monster->x = next_x;
		}
		else
		{
			// Reverse direction if the move is blocked
			monster->direction *= -1;
		}

		if (monster->x == vars->farmer.x / TILE_SIZE && monster->y == vars->farmer.y / TILE_SIZE)
        {
            game_over(vars);
            return (0);
		}
	}

	// Request a redraw
	redraw_window(vars);

	return (0);
}*/

void	game_over(t_vars *vars)
{
	int	center_x;
	int	center_y;

	center_x = vars->map.width / 2;
	center_y = vars->map.height / 2;
	mlx_string_put(vars->mlx, vars->win, center_x - 60, center_y - 10,
		0xFFFFFF, "GAME OVER :(");
	mlx_string_put(vars->mlx, vars->win, center_x - 100, center_y + 15,
		0xFFFFFF, "You got caught by a monster");
	mlx_string_put(vars->mlx, vars->win, center_x - 75, center_y + 40,
		0xFFFFFF, "Press ESC to exit");
	vars->map.end = 1;
}
