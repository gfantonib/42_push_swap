NAME = push_swap

LIBFT = libft/libft.a
LIBFT_PATH = libft/

CFLAGS	= -Wextra -Wall -Werror

HEADERS	= -I ./includes/

MK = mkdir -p

SOURCE_PATH = sources/

BONUS_SOURCE_PATH = sources_bonus/

SRCS	= \
			cost.c \
			do_move.c \
			initialization.c \
			input_check_utils.c \
			input_check.c \
			main.c \
			position.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			sort_tiny.c \
			sort.c \
			stack.c \
			swap.c \
			utils.c

OBJECTS_PATH = objects

OBJS = $(addprefix $(OBJECTS_PATH)/, $(SRCS:%.c=%.o))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJECTS_PATH)/%.o: $(SOURCE_PATH)%.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJECTS_PATH) 
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re val