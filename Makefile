# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 12:02:40 by urycherd          #+#    #+#              #
#    Updated: 2022/03/15 12:39:54 by urycherd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADER = pipex.h

SRCS = pipex.c pipe_func.c sup_func.c free_func.c ft_split.c

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${OBJS} -o ${NAME}
	@echo "done!"

${OBJS}: ${HEADER}

.c.o:
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@echo "cleaning..."
	@${RM} ${OBJS}
	@echo "obj deleted"

fclean:
	@echo "cleaning all..."
	@${RM} ${NAME} ${OBJS}
	@echo "cleaned"

re: fclean all

.PHONY: all clean fclean re

