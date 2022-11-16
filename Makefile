# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 17:26:47 by mmardi            #+#    #+#              #
#    Updated: 2022/03/22 13:14:46 by mmardi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = so_long

NAME2 = so_long_bonus

CFLAGS = -Wall -Wextra -Werror

SOURCE1 = ./mandatory/check_map.c ./mandatory/ft_putnbr.c \
			./mandatory/ft_split.c ./mandatory/libft.c \
			./mandatory/move.c ./mandatory/put_map.c \
			./mandatory/read_map.c ./mandatory/so_long.c \

SOURCE2 = ./bonus/check_map.c ./bonus/ft_putnbr.c \
			./bonus/ft_split.c ./bonus/libft.c \
			./bonus/move.c ./bonus/put_map.c \
			./bonus/read_map.c ./bonus/so_long_bonus.c \
			./bonus/move_enemy.c \

DEFS1 = ./mandatory/so_long.h

DEFS2 = ./bonus/so_long_bonus.h

MLX = -lmlx -framework OpenGL -framework AppKit

OBJ1 = $(SOURCE1:.c=.o)

OBJ2 = $(SOURCE2:.c=.o)

all: $(NAME1)
$(NAME1) : $(DEFS1) $(OBJ1)
	@$(CC) $(CFLAGS) $(SOURCE1)  $(MLX) -o $(NAME1)

bonus: $(NAME2)
$(NAME2) : $(DEFS2) $(OBJ2)
	@$(CC) $(CFLAGS) $(SOURCE2)  $(MLX) -o $(NAME2)
	
clean:
	@rm -f $(OBJ1) $(OBJ2)

fclean: clean
	@rm -f $(NAME1) $(NAME2)

re: fclean all

reb: fclean bonus