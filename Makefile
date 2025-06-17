# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 14:34:01 by vinguyen          #+#    #+#              #
#    Updated: 2025/06/17 14:48:27 by vinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC =	pipex.c \
		
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
