NAME = so_long_test

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "\n========== TESTING VALID MAPS =========="
	@echo "\n--- Test 1: Easy Small Map ---"
	./$(NAME) maps/map_easy_small.ber
	@echo "\n--- Test 2: Easy Large Map ---"
	./$(NAME) maps/map_easy_large.ber
	@echo "\n--- Test 3: Hard Maze ---"
	./$(NAME) maps/map_hard_maze.ber
	@echo "\n--- Test 4: Hard Spiral ---"
	./$(NAME) maps/map_hard_spiral.ber
	@echo "\n--- Test 5: Hard Rooms ---"
	./$(NAME) maps/map_hard_rooms.ber
	@echo "\n\n========== TESTING INVALID MAPS =========="
	@echo "\n--- Test 6: No Exit (should FAIL) ---"
	-./$(NAME) maps/map_invalid_no_exit.ber
	@echo "\n--- Test 7: Not Rectangular (should FAIL) ---"
	-./$(NAME) maps/map_invalid_not_rectangular.ber
	@echo "\n--- Test 8: No Valid Path (should FAIL) ---"
	-./$(NAME) maps/map_invalid_no_path.ber
	@echo "\n\n========== ALL TESTS COMPLETED =========="

.PHONY: all clean fclean re test
