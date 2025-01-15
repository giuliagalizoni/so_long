test:
	cc -Wall -Wextra -Werror so_long.c ./mlx/libmlx.a -framework OpenGL -framework AppKit -o so_long
