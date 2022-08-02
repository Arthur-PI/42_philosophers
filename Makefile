# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apigeon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 16:08:04 by apigeon           #+#    #+#              #
#    Updated: 2022/08/02 21:16:11 by apigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


### COMPILATION ###
CC		= cc
MAKE	= make
CFLAGS	= -Wall -Werror -Wextra

### EXECUTABLE ###
NAME		= philo
ARGS		= args

### INCLUDES ###
OBJ_DIR		= bin
SRC_DIR		= src
HEADER		= incl

### SOURCE FILES ###
SRCS	= 	main.c

### HEADER FILES ###
HEADER_FILES	= philo.h
HEADERS			= $(addprefix $(HEADER)/, $(HEADER_FILES))

### OBJECTS ###
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

### COLORS ###
RESET	= \033[0m
BLACK	= \034[1;30m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m

### OTHERS ###
UNAME_S = $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	VALGRIND = leaks --list --groupByType --atExit --
else
	VALGRIND = valgrind --track-origins=yes --leak-check=full
endif

### RULES ###
all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME): $(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(RESET)"
	@echo "$(NAME): $(GREEN)Project successfully compiled$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT_DIR)/$(HEADER) -c $< -o $@
	@echo "$(NAME): $(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(RESET)"

run: $(NAME)
	@./$(NAME) $(ARGS)

val: $(NAME)
	@$(VALGRIND) ./$(NAME) $(ARGS)

clean:
	@echo "$(NAME): $(RED)Supressing object files$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@echo "$(NAME): $(RED)Supressing program file$(RESET)"
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
