NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux

SRCS = 	main.c $(wildcard check_map/*.c) \
		$(wildcard game/*.c) $(wildcard render/*.c)

OBJS = $(SRCS:.c=.o)

INCLUDES = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(LIBFT) mlx $(NAME)
	@echo " ===== COMPLETE! ===== "

$(NAME): $(OBJS)
	@echo "Linking so_long..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c so_long.h
	@echo "***Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "*Compiling libft..."
	@make -C $(LIBFT_DIR) > /dev/null

mlx:
	@echo "**Compiling minilibx..."
	@make -C $(MLX_DIR) > /dev/null

clean:
	@echo "=== CLEAR OBJECTS ==="
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "=.=.=.=.= CLEAR ALL =.=.=.=.="
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re mlx