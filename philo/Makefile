
NAME = philo

BUILD_FLAGS = -Wall -Wextra -Werror #-fsanitize=address,undefined -g

COMMON_SRC = str \
			time \
			validate \
			nbr \
			memory

INIT_SRC = init_forks \
			init_philo \
			init_data

COMMONSRCPRE = $(addprefix ./src/common/, $(COMMON_SRC))
COMMONSRCSUFF = $(addsuffix .c, $(COMMONSRCPRE))
INITSRCPRE = $(addprefix ./src/init/, $(INIT_SRC))
INITSRCSUFF = $(addsuffix .c, $(INITSRCPRE))
HSUFF = $(addsuffix .h, $(H_FILES))

.PHONY = all
all: $(NAME)

$(NAME):
	cc $(BUILD_FLAGS) $(COMMONSRCSUFF) $(INITSRCSUFF) main.c -o $(NAME)

.PHONY: clean
clean:
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

