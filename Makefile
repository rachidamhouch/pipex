# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 11:17:51 by ramhouch          #+#    #+#              #
#    Updated: 2022/11/19 11:17:53 by ramhouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=pipex
BONUS=pipex_bonus
CFLAGS=-Wall -Wextra -Werror
SRC = main.c split.c check.c strlen.c strncmp.c exec_cmd.c reader.c
OBJ = $(SRC:.c=.o)
BONUS_SRC= main_bonus.c split.c check.c strlen.c strncmp.c exec_cmd.c reader.c get_next_line.c get_next_line_utils.c here_doc.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(BONUS): $(BONUS_OBJ)
		cc -o $(BONUS) $(BONUS_OBJ)

$(NAME): $(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ) $(BONUS_OBJ)
fclean: clean
		rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: clean all fclean re bonus