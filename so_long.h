/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:27 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/17 18:39:44 by ggalizon         ###   ########.fr       */
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

# define TILE_SIZE 48
// linux
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define ESC 65307

// macOS
// #define UP 126
// #define DOWN 125
// #define RIGHT 124
// #define LEFT 123
// #define ESC 53

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map {
	char	**arr;
}	t_map;

typedef struct s_player {
	void	*front;
	void	*start;
	int		x;
	int		y;
}	t_player;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_img		ground;
	t_img		wall;
	t_player	farmer;
	t_img		carrot;
	t_img		house;
	t_map		map;
}	t_vars;

char	**make_map_arr(char *map_path);
void	tile_window(t_vars *vars);
void	redraw_window(t_vars *vars);

#endif
