# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/22 16:14:59 by iwillens          #+#    #+#              #
#    Updated: 2021/08/25 18:05:11 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 17:38:02 by iwillens          #+#    #+#              #
#    Updated: 2021/08/21 19:17:21 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

ORIGINAL = orig_containers

CC = clang++
CCFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC_DIR = ./srcs
OBJ_DIR = ./build
INC_DIR = ./includes

FT_SRCS = ${SRC_DIR}/main.cpp

ORIG_SRCS = ${SRC_DIR}/main.cpp

FT_OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${FT_SRCS})
ORIG_OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${ORIG_SRCS})

all: ${NAME}

${NAME}: ${PS_OBJS} ${INC_DIR}
	${CC} ${CCFLAGS} ${FT_OBJS} -I ${INC_DIR} -o ${NAME}

original: ${ORIGINAL}

${ORIGINAL}: ${ORIG_OBJS} ${INC_DIR}
	${CC} ${CCFLAGS} ${ORIG_OBJS} -I ${INC_DIR} -o ${ORIGINAL}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_DIR}
	mkdir -p ${OBJ_DIR}
	${CC} -c ${CCFLAGS} $< -I ${INC_DIR} -o $@

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ./${NAME}
	rm -rf ./${ORIGINAL}

re: fclean all

test: re
	./${NAME}
