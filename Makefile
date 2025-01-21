# for mac
test:
	cc -Wall -Wextra -Werror src/*.c -Llibft -lft -Ilibft ./mlx/libmlx.a -framework OpenGL -framework AppKit -o so_long

# for Linux
# test:
# 	cc -Wall -Wextra -Werror so_long.c -Llibft -lft -Ilibft -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o so_long

# rule for bonus
# compiling libft
