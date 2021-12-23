# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spzona <spzona@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 17:29:08 by spzona            #+#    #+#              #
#    Updated: 2021/12/23 19:28:39 by spzona           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra 

NAME = libftprintf.a
LIB = libft/libft.a

SRC = src/ft_printf.c src/ft_utils

OBJS = $(patsubst %.c,%.o,$(SRC))

HEADER = ft_printf.h

$(NAME): $(OBJ) $(HEADER)
				@echo "Compiling libft"
				@make -C libft
				@cp $(LIB) $(NAME) 
				@ar rcs $(NAME) $?
				@echo "Making $(NAME)"

all: $(NAME)

.c.o: $(HEADER)
				@cc $(FLAG) -c $< -o $@ -I $(HEADER)
				@echo "Compiling $<"


clean:
				@rm -f $(OBJ)
				@echo "OBJ deleted"
				@make clean -C libft
				@echo "OBJ in libft deleted"

fclean: clean
				@rm -f $(NAME)
				@echo "Everything deleted"
				@make fclean -C libft
				@echo "OBJ in libft deleted"


re: fclean all 

.PHONY: all, clean, fclean, re