# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 06:12:21 by sismaili          #+#    #+#              #
#    Updated: 2022/01/09 15:36:28 by sismaili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SRV = server.c

SRC_CLT = client.c

SRC_SRV_BONUS = server_bonus.c

SRC_CLT_BONUS = client_bonus.c


OBJS_SRV = ${SRC_SRV:.c=.o}

OBJS_CLT = ${SRC_CLT:.c=.o}

OBJS_SRV_BONUS = ${SRC_SRV_BONUS:.c=.o}

OBJS_CLT_BONUS = ${SRC_CLT_BONUS:.c=.o}

NAME1 = server
NAME2 = client

NAME    = minitalk

CC      = cc

RM      = rm -f

FT_PRINTF = ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS_SRV} ${OBJS_CLT}
	${CC} ${CFLAGS} ${SRC_SRV} ${FT_PRINTF} -o ${NAME1}
	${CC} ${CFLAGS} ${SRC_CLT} ${FT_PRINTF} -o ${NAME2}

bonus: ${OBJS_SRV_BONUS} ${OBJS_CLT_BONUS}
	${CC} ${CFLAGS} ${SRC_SRV_BONUS} -o ${NAME1} ${FT_PRINTF}
	${CC} ${CFLAGS} ${SRC_CLT_BONUS} -o ${NAME2} ${FT_PRINTF}

all: $(NAME)

clean:
	${RM} ${OBJS_SRV} ${OBJS_CLT} ${OBJS_SRV_BONUS} ${OBJS_CLT_BONUS}

fclean: clean
		${RM} ${NAME} ${NAME1} ${NAME2}

re: fclean all

.PHONY: minitalk bonus all clean fclean re