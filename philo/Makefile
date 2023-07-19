# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 14:38:49 by meskelin          #+#    #+#              #
#    Updated: 2023/07/18 20:22:48 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

BUILD_FLAGS = -Wall -Wextra -Werror -o2 #-fsanitize=address,undefined -g #-fsanitize=thread

COMMON_SRC =	validate \
				nbr \
				ft_print \
				sleep \
				time \
				memory

INIT_SRC =	init \
			init_forks \
 			init_philos \
			clean

SIM_SRC =	forks \
			philosophers \
			routine \
			simulation \
			threads \
			checks

COMMONSRCPRE = $(addprefix ./common/, $(COMMON_SRC))
COMMONSRCSUFF = $(addsuffix .c, $(COMMONSRCPRE))
INITSRCPRE = $(addprefix ./data/, $(INIT_SRC))
INITSRCSUFF = $(addsuffix .c, $(INITSRCPRE))
SIMSRCPRE = $(addprefix ./simulation/, $(SIM_SRC))
SIMSRCSUFF = $(addsuffix .c, $(SIMSRCPRE))
HSUFF = $(addsuffix .h, $(H_FILES))

.PHONY = all
all: $(NAME)

$(NAME):
	cc $(BUILD_FLAGS) $(COMMONSRCSUFF) $(SIMSRCSUFF) $(INITSRCSUFF) main.c -o $(NAME)

.PHONY: clean
clean:
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

