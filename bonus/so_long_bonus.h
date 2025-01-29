/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:27 by ggalizon          #+#    #+#             */
/*   Updated: 2025/01/29 22:03:39 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define WALL "assets/Tree.xpm"
# define GROUND "assets/Ground.xpm"
// # define FARMER "assets/Player.xpm"
# define FARMER_START "assets/Player_start.xpm"
# define CARROT "assets/Carrot_big.xpm"
# define HOUSE "assets/House.xpm"
# define PIG "assets/Pig.xpm"

# define FARMER_FRONT_1 "assets/Player_front_1.xpm"
# define FARMER_FRONT_2 "assets/Player_front_2.xpm"
# define FARMER_LEFT_1 "assets/Player_left_1.xpm"
# define FARMER_LEFT_2 "assets/Player_left_2.xpm"
# define FARMER_RIGHT_1 "assets/Player_right_1.xpm"
# define FARMER_RIGHT_2 "assets/Player_right_2.xpm"
# define FARMER_BACK_1 "assets/Player_back_1.xpm"
# define FARMER_BACK_2 "assets/Player_back_2.xpm"
# define MONSTER "assets/Slime.xpm"

# define TILE_SIZE 48
#define ANIMATION_SPEED 20

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
	int		p;
	int		e;
	int		c_reach;
	int		end;
	int		invalid;
}	t_map;

typedef struct s_player
{
	void	*front;
	void	*start;
	void	*front_1;
	void	*front_2;
	void	*left_1;
	void	*left_2;
	void	*right_1;
	void	*right_2;
	void	*back_1;
	void	*back_2;
	int		x;
	int		y;
	int		mov_count;
}	t_player;

typedef struct s_monster
{
	int		x;            // Monster's x position (in tiles)
	int		y;            // Monster's y position (in tiles)
	int		direction;    // 1 for right, -1 for left
	int		current_frame;// 0 or 1 to switch between images
	int		timer;        // Timer to control animation speed
	void	*img;        // Monster image 1
} t_monster;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			key;
	t_player	farmer;
	t_img		ground;
	t_img		wall;
	t_img		carrot;
	t_img		house;
	t_map		map;
	t_img		pig;
	t_monster	*monsters;
	int			monster_count;
	void		*monster_img;
}	t_vars;

void	init_map(t_vars *vars, char *map_path);
void	redraw_window(t_vars *vars); //tirei a key
void	init_img(t_vars *vars);
void	move_farmer(t_vars *vars, int key);
int		error_message(char *message);
int		check_map(t_vars *vars);
void	free_map(char **arr);
void	cleanup(t_vars *vars);
int		exit_sucess(t_vars *vars);
int		validate_map(t_vars *vars);

void	put_movcount(t_vars *vars);
void	farmer_animation(t_vars *vars, int keycode);
int		animate_monsters(t_vars *vars);
void	init_monsters(t_vars *vars);

void	game_over(t_vars *vars);

#endif
