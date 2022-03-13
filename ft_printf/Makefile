# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 15:30:13 by hjanis            #+#    #+#              #
#    Updated: 2022/03/11 17:39:56 by hjanis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_char.c ft_hex.c ft_int.c  ft_itoa.c ft_itoabase.c \
					ft_printf.c ft_putnbr_base.c ft_strdup.c ft_strlen.c ft_unsigned.c \
					ft_isdigit.c   
OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_char.c ft_hex.c ft_int.c  ft_itoa.c ft_itoabase.c \
					ft_printf.c ft_putnbr_base.c ft_strdup.c ft_strlen.c ft_unsigned.c \
					ft_isdigit.c 
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME        = libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus