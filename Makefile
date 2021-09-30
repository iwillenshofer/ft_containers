# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 17:38:02 by iwillens          #+#    #+#              #
#    Updated: 2021/09/29 21:05:50 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
NAME_STD = std_containers

CC = clang++
CCFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -std=c++98 -pedantic

SRC_DIR = ./tests
OBJ_DIR = ./build_ft
STD_OBJ_DIR = ./build_std

INC_DIR = ./includes

INCLUDES = ${INC_DIR}/algorithm.hpp \
			${INC_DIR}/iterator_traits.hpp \
			${INC_DIR}/iterators.hpp \
			${INC_DIR}/reverse_iterator.hpp \
			${INC_DIR}/type_traits.hpp \
			map.hpp \
			stack.hpp \
			vector.hpp


SRCS = ${SRC_DIR}/main.cpp \
				${SRC_DIR}/Tester.cpp \
				${SRC_DIR}/test_utilities.cpp \
				${SRC_DIR}/test_reverseiterator.cpp \
				${SRC_DIR}/vector_constructors.cpp \
				${SRC_DIR}/vector.cpp

FT_OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS})
STD_OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS})

all: ${NAME} ${NAME_STD}

${NAME}: ${PS_OBJS} ${INCLUDES}
	${CC} ${CCFLAGS} ${FT_OBJS} -DORIGINAL_STD=0 -I. -I ${INC_DIR} -o ${NAME}

${NAME_STD}: ${PS_OBJS} ${INCLUDES}
	${CC} ${CCFLAGS} ${STD_OBJS} -DORIGINAL_STD=1 -I. -I ${INC_DIR} -o ${NAME_STD}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_DIR}
	mkdir -p ${OBJ_DIR}
	${CC} -c ${CCFLAGS} $< -I. -I ${INC_DIR} -o $@

${STD_OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_DIR}
	mkdir -p ${STD_OBJ_DIR}
	${CC} -c ${CCFLAGS} $< -I. -I ${INC_DIR} -o $@


clean:
	rm -rf ${OBJ_DIR}
	rm -rf ${STD_OBJ_DIR}

fclean: clean
	rm -rf ./${NAME}
	rm -rf ./${NAME_STD}

re: fclean all

test: re
	./${NAME}
