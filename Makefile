NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
ifeq ($(shell uname -s), Linux)
    MLXFLAGS = -L$(MLX_DIR) -lmlx_Linux -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lz
else
    MLXFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

REMOVE = rm -f

MANDATORY_DIR = mandatory/
BONUS_DIR = bonus/
SRC_DIR = src/

SRCS = \
    $(MANDATORY_DIR)$(SRC_DIR)so_long.c \
    $(MANDATORY_DIR)$(SRC_DIR)check_map.c \
    $(MANDATORY_DIR)$(SRC_DIR)check_path.c \
    $(MANDATORY_DIR)$(SRC_DIR)clean_and_exit.c \
    $(MANDATORY_DIR)$(SRC_DIR)init_images.c \
    $(MANDATORY_DIR)$(SRC_DIR)movements.c \
    $(MANDATORY_DIR)$(SRC_DIR)put_img.c \
    $(MANDATORY_DIR)$(SRC_DIR)read_map.c

BONUS_SRCS = \
    $(BONUS_DIR)$(SRC_DIR)so_long_bonus.c \
    $(BONUS_DIR)$(SRC_DIR)bonus_check_map.c \
    $(BONUS_DIR)$(SRC_DIR)bonus_check_path.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m

all: $(LIBFT) $(NAME)
	@echo "$(GREEN)Compilation of mandatory files completed!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling MiniLibX...$(RESET)"
	$(MAKE) -C $(MLX_DIR)
	@echo "$(CYAN)Linking so_long...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)so_long executable created successfully!$(RESET)"

bonus: $(LIBFT) $(NAME_BONUS)
	@echo "$(GREEN)Compilation of bonus files completed!$(RESET)"

$(NAME_BONUS): $(BONUS_OBJS)
	@echo "$(YELLOW)Compiling MiniLibX...$(RESET)"
	$(MAKE) -C $(MLX_DIR)
	@echo "$(CYAN)Linking so_long_bonus...$(RESET)"
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)so_long_bonus executable created successfully!$(RESET)"

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(REMOVE) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "$(YELLOW)Removing executables...$(RESET)"
	$(REMOVE) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
