#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include <stdlib.h>

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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_img	ground;
	t_img	wall;
	t_img	farmer;
}				t_vars;




#endif
