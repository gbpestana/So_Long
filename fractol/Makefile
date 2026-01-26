# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 13:50:32 by thiagouemur       #+#    #+#              #
#    Updated: 2025/09/19 14:25:24 by tkenji-u         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	src/main.c			\
		src/utils.c			\
		src/mandelbrot.c	\
		src/julia.c			\
		src/common.c		\
		src/hooks.c			
OBJS = $(SRCS:.c=.o)
INCLUDES = -I ./include -I ./lib/minilibx-linux
LIBS = -L ./lib/minilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./lib/minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C ./lib/minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	@make -C ./lib/minilibx-linux fclean

re: fclean all

.PHONY: all clean fclean re