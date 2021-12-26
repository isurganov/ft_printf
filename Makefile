# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 17:29:08 by spzona            #+#    #+#              #
#    Updated: 2021/12/26 04:39:59 by Arbiter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra 

NAME = libftprintf.a

SRC = ft_printf.c ft_utils.c ft_utils_2.c

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

$(NAME): $(OBJ) $(HEADER)
				@ar rcs $(NAME) $(OBJ)
				@echo "$(NAME) created"
				@ranlib $(NAME)

all: $(NAME)

%.o: %.c $(HEADER)
				@cc $(FLAG) -c $< -o $@ -I $(HEADER)
				@echo "Compiling $<"


clean:
				@rm -f $(OBJ)
				@echo "OBJ deleted"

fclean: clean
				@rm -f $(NAME)
				@echo "Everything deleted"

re: fclean all 

.PHONY: all, clean, fclean, re