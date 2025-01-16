#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>

#define TILE_SIZE 48

#define WALL "assets/Tree.xpm"
#define GROUND "assets/Ground.xpm"
#define FARMER "assets/Player_front.xpm"

#define WIDTH 720
#define HEIGHT 480

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map {
	char *arr[9];
} t_map;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_img	ground;
	t_img	wall;
	t_img	farmer;
	t_map	map;
}				t_vars;

#endif
