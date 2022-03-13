# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 17:39:17 by hjanis            #+#    #+#              #
#    Updated: 2022/03/11 17:45:42 by hjanis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS	=	so_long_bonus
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
PFT			=	ft_printf/libftprintf.a
INC			=	-I ./include/so_long.h -I ./ft_printf -I ./mlx
SRC_BONUS	=	main_bonus.c map_filler_bonus.c map_valid_bonus.c map_bonus.c player_bonus.c draw_bonus.c \
			get_next_line.c get_next_line_utils.c enemy_bonus.c \
			validation_utils_bonus.c draw_utils_bonus.c draw_open_bonus.c
LIB			=	-lmlx -framework OpenGL -framework AppKit
OBJ_BONUS	=	$(patsubst src%, obj%, $(SRC_BONUS:.c=.o))
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
HEADER		= 	./include/so_long.h
SRC 		= main.c map_filler.c map_valid.c map.c player.c draw.c \
			get_next_line.c get_next_line_utils.c enemy.c \
			validation_utils.c draw_utils.c draw_open.c
all:		$(MLX) $(PFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(PFT)  -o $@ $^ $(LIB)

$(MLX):
	@echo " [ .. ] | Compiling minilibx.."
	@make -s -C mlx
	@echo " [ OK ] | Minilibx ready!"

$(PFT):
	@echo " [ .. ] | Compiling printf.."
	@make -s -C ft_printf
	@echo " [ OK ] | printf ready!"

obj:
			@mkdir -p obj

%.o:	%.c ./include/so_long.h
			$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@

clean:
			@make -s $@ -C ft_printf
			@rm -rf $(OBJ) $(OBJ_BONUS) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C ft_printf
			@rm -rf $(NAME) $(NAME_BONUS)
			@echo "binary file removed."

re:			fclean all bonus

bonus:		$(MLX) $(PFT) obj $(NAME_BONUS)

$(NAME_BONUS):	$(OBJ_BONUS)
			$(CC) $(FLAGS) $(PFT)  -o $@ $^ $(LIB)

.PHONY:		all clean fclean re bonus