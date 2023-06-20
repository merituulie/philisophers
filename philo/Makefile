
NAME = philo

BUILD_FLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g

COMMON_SRC = time \
			validate \
			nbr \
			memory \
			sleep \
			ft_print

INIT_SRC = init_forks \
			init_philo \
			init_data \
			clean_up

SIM_SRC = threads \
		check \
		eat \
		simulation \
		philosophers

COMMONSRCPRE = $(addprefix ./src/common/, $(COMMON_SRC))
COMMONSRCSUFF = $(addsuffix .c, $(COMMONSRCPRE))
INITSRCPRE = $(addprefix ./src/data/, $(INIT_SRC))
INITSRCSUFF = $(addsuffix .c, $(INITSRCPRE))
SIMSRCPRE = $(addprefix ./src/simulation/, $(SIM_SRC))
SIMSRCSUFF = $(addsuffix .c, $(SIMSRCPRE))
HSUFF = $(addsuffix .h, $(H_FILES))

.PHONY = all
all: $(NAME)

$(NAME):
	cc $(BUILD_FLAGS) $(COMMONSRCSUFF) $(INITSRCSUFF) $(SIMSRCSUFF) main.c -o $(NAME)

.PHONY: clean
clean:
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

