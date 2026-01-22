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

all: banner $(LIBFT) mlx $(NAME)
	@echo " ===== COMPLETE! ===== "

banner:
	@echo "Compiling so_long..."

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

.PHONY: all clean fclean re mlx banner

# NAME = so_long

# CC = cc
# CFLAGS = -Wall -Werror -Wextra -g

# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a

# MLX_DIR = minilibx-linux
# MLX = $(MLX_DIR)/libmlx.a

# SRCS = $(wildcard *.c)

# OBJS = $(SRCS:.c=.o)

# INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)

# MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# all: $(NAME)
# 	@echo "-----COMPLETE!!------"

# $(NAME): $(OBJS)
# 	@echo "-linking objects-"
# 	@make -C $(LIBFT_DIR)
# 	@make -C $(MLX_DIR)
# 	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

# %.o: %.c so_long.h
# 	@echo "--compiling--"
# 	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean:
# 	@echo "*removing objects*"
# 	@rm -f $(OBJS)
# 	@make -C $(LIBFT_DIR) clean

# fclean: clean
# 	@echo "**removing all**"
# 	@rm -f $(NAME)
# 	@make -C $(LIBFT_DIR) fclean

# re: fclean all

# .PHONY: all clean fclean re test
