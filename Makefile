# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 17:38:02 by iwillens          #+#    #+#              #
#    Updated: 2021/10/03 17:42:42 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
NAME_STD = std_containers

CC = clang++
CCFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -std=c++98 -pedantic -ferror-limit=10000

SRC_DIR = ./tests
OBJ_DIR = ./build
FT_OBJ_DIR = ${OBJ_DIR}/ft
STD_OBJ_DIR = ${OBJ_DIR}/std

INC_DIR = ./includes

INCLUDES = ${INC_DIR}/ft_algorithm.hpp \
			${INC_DIR}/ft_iterator_traits.hpp \
			${INC_DIR}/ft_iterators.hpp \
			${INC_DIR}/ft_reverse_iterator.hpp \
			${INC_DIR}/ft_type_traits.hpp \
			map.hpp \
			stack.hpp \
			vector.hpp

SRCS = ${SRC_DIR}/main.cpp \
			${SRC_DIR}/Tester.cpp \
			${SRC_DIR}/utilities/test_utilities.cpp \
			${SRC_DIR}/utilities/test_reverseiterator.cpp \
			${SRC_DIR}/vector/vector_constructors.cpp \
			${SRC_DIR}/vector/vector_capacity.cpp \
			${SRC_DIR}/vector/vector_iterators.cpp \
			${SRC_DIR}/vector/vector_elementaccess.cpp \
			${SRC_DIR}/vector/vector_modifiers.cpp \
			${SRC_DIR}/vector/vector_overloads.cpp \
			${SRC_DIR}/vector/vector_tests.cpp \
			${SRC_DIR}/map/map_tests.cpp \
			${SRC_DIR}/map/map_constructors.cpp \
			${SRC_DIR}/map/map_largetests.cpp

	

				

FT_OBJS = $(patsubst ${SRC_DIR}/%.cpp, ${FT_OBJ_DIR}/%.o, ${SRCS})
STD_OBJS = $(patsubst ${SRC_DIR}/%.cpp, ${STD_OBJ_DIR}/%.o, ${SRCS})

all: ${NAME} ${NAME_STD}

${NAME}: ${FT_OBJS} ${INCLUDES}
	@echo "\033[92mBuilding ./ft_containers. \033[0m"
	@${CC} ${CCFLAGS} ${FT_OBJS} -DORIGINAL_STD=0 -I. -I ${INC_DIR} -o ${NAME}

${NAME_STD}: ${STD_OBJS} ${INCLUDES}
	@echo "\033[92mBuilding ./std_containers. \033[0m"
	@${CC} ${CCFLAGS} ${STD_OBJS} -DORIGINAL_STD=1 -I. -I ${INC_DIR} -o ${NAME_STD}

${FT_OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${INC_DIR} ${INCLUDES}
	@mkdir -p $(dir $@)
	@${CC} -c ${CCFLAGS} $< -DORIGINAL_STD=0 -I. -I ${INC_DIR} -o $@

${STD_OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${INC_DIR} ${INCLUDES}
	@mkdir -p $(dir $@)
	@${CC} -c ${CCFLAGS} $< -DORIGINAL_STD=1 -I. -I ${INC_DIR} -o $@

clean:
	@rm -rf ${OBJ_DIR}

fclean: clean
	@rm -rf ./${NAME}
	@rm -rf ./${NAME_STD}

re: fclean all

test: re
	./${NAME}

diff: all
	@echo "\033[92mDifference between std:: and ft:: tests: \033[0m"
	@/bin/bash -c "diff <(./ft_containers) <(./std_containers)" || true

FORMAT = "%e elapsed. %U user. %S system. %P CPU."
time: all
	@echo "\033[92mTime difference between std:: and ft:: tests: \033[0m"
	@echo "\033[93m./ft_containers \033[0m"
	@time -f ${FORMAT} ./ft_containers > /dev/null
	@echo "\033[93m./std_containers \033[0m"
	@time -f ${FORMAT} ./std_containers > /dev/null

time_mac: all
	@echo "\033[92mTime difference between std:: and ft:: tests: \033[0m"
	@echo "\033[93m./ft_containers \033[0m"
	@/bin/bash -c "time ./ft_containers > /dev/null"
	@echo "\033[93m./std_containers \033[0m"
	@/bin/bash -c "time ./std_containers > /dev/null"
	