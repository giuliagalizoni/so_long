/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:27 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/20 17:15:24 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

# define WALL "assets/Tree.xpm"
# define GROUND "assets/Ground.xpm"
# define FARMER "assets/Player.xpm"
# define FARMER_START "assets/Player_start.xpm"
# define CARROT "assets/Carrot_big.xpm"
# define HOUSE "assets/House.xpm"
# define PIG "assets/Pig.xpm"

# define TILE_SIZE 48

# ifdef __APPLE__ // macOS
#  define UP 126
#  define DOWN 125
#  define RIGHT 124
#  define LEFT 123
#  define ESC 53
# elif __linux__ // Linux
#  define UP 65362
#  define DOWN 65364
#  define RIGHT 65363
#  define LEFT 65361
#  define ESC 65307
# else
#  error "Unsupported operating system"
# endif

// linux
// # define UP 65362
// # define DOWN 65364
// # define RIGHT 65363
// # define LEFT 65361
// # define ESC 65307

// macOS
// # define UP 126
// # define DOWN 125
// # define RIGHT 124
// # define LEFT 123
// # define ESC 53

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	**arr;
	int		width;
	int		height;
	int		c;
	int		end;
}	t_map;

typedef struct s_player
{
	void	*front;
	void	*start;
	int		x;
	int		y;
	int		mov_count;
}	t_player;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_player	farmer;
	t_img		ground;
	t_img		wall;
	t_img		carrot;
	t_img		house;
	t_map		map;
	t_img		pig;
}	t_vars;

void	init_map(t_vars *vars, char *map_path);
// void	tile_window(t_vars *vars);
void	redraw_window(t_vars *vars);
void	init_img(t_vars *vars);
void	move_farmer(t_vars *vars, int key);

#endif
