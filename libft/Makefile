# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 17:53:09 by ggalizon          #+#    #+#              #
#    Updated: 2024/11/26 11:12:10 by ggalizon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
REMOVE = rm -f

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS_SRCS  = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS 	= $(BONUS_SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# rule for testing
main:
	$(CC) $(FLAGS) -o main main.c $(NAME) $(INCLUDE)

main_bonus:
	$(CC) $(FLAGS) -o main_bonus main_bonus.c $(NAME) $(INCLUDE)

clean:
	$(REMOVE) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(REMOVE) $(NAME) main main_bonus

re: fclean all

.PHONY: all bonus clean fclean re main main_bonus
