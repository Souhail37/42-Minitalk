# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 20:53:48 by sismaili          #+#    #+#              #
#    Updated: 2021/12/22 18:48:52 by sismaili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c	\
		ft_putchar.c	\
		ft_putstr.c	\
		ft_putnbr.c	\
		ft_putnbr_unsigned.c	\
		ft_hexa.c	\
		ft_memory.c	\
		ft_flags2.c	\
		ft_sharp.c	\
		ft_space_plus.c	\

SRCS_BONUS = ft_printf.c	\
			ft_putchar.c	\
			ft_putstr.c	\
			ft_putnbr.c	\
			ft_putnbr_unsigned.c	\
			ft_hexa.c	\
			ft_memory.c	\
			ft_flags2.c	\
			ft_sharp.c	\
			ft_space_plus.c	\

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libftprintf.a

%.o : %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus: ${OBJS_BONUS}
	ar rc ${NAME} ${OBJS_BONUS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re