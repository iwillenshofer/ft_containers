# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 17:38:02 by iwillens          #+#    #+#              #
#    Updated: 2021/09/16 10:18:48 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

ORIGINAL = orig_containers

CC = clang++
CCFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC_DIR = ./tests
OBJ_DIR = ./build
INC_DIR = ./includes

INCLUDES = ${INC_DIR}/algorithm.hpp \
			${INC_DIR}/iterator_traits.hpp \
			${INC_DIR}/iterators.hpp \
			${INC_DIR}/reverse_iterator.hpp \
			${INC_DIR}/type_traits.hpp \
			map.hpp \
			stack.hpp \
			vector.hpp


FT_SRCS = ${SRC_DIR}/main.cpp

ORIG_SRCS = ${SRC_DIR}/main.cpp

FT_OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${FT_SRCS})
ORIG_OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${ORIG_SRCS})

all: ${NAME}

${NAME}: ${PS_OBJS} ${INCLUDES}
	${CC} ${CCFLAGS} ${FT_OBJS} -I. -I ${INC_DIR} -o ${NAME}

original: ${ORIGINAL}

${ORIGINAL}: ${ORIG_OBJS} ${INCLUDES}
	${CC} ${CCFLAGS} ${ORIG_OBJS} -I ${INC_DIR} -o ${ORIGINAL}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_DIR}
	mkdir -p ${OBJ_DIR}
	${CC} -c ${CCFLAGS} $< -I. -I ${INC_DIR} -o $@

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ./${NAME}
	rm -rf ./${ORIGINAL}

re: fclean all

test: re
	./${NAME}
