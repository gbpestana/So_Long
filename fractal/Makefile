# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 12:32:33 by rgomes-g          #+#    #+#              #
#    Updated: 2025/12/17 11:44:48 by rgomes-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===============================
#        CONFIGURAÇÃO
# ===============================

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
SRCS = $(SRCDIR)/color.c \
       $(SRCDIR)/fractals.c \
       $(SRCDIR)/hooks.c \
       $(SRCDIR)/init.c \
       $(SRCDIR)/main.c \
       $(SRCDIR)/print_help.c \
       $(SRCDIR)/render.c \
       $(SRCDIR)/utils.c \

OBJS = $(SRCS:.c=.o)

# MLX
MLX_DIR = minilibx-linux
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = -I includes -I $(MLX_DIR)

# ===============================
#            REGRAS
# ===============================

all: $(MLX) $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)

# Compila arquivos do srcs
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ===============================
#       MLX (clone + build)
# ===============================

$(MLX):
	@if [ ! -d $(MLX_DIR) ]; then \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@if [ ! -f $(MLX) ]; then \
		$(MAKE) -C $(MLX_DIR); \
	fi

# ===============================
#           LIMPEZA
# ===============================

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
