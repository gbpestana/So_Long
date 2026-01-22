NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test
