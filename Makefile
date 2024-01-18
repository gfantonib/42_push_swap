NAME = push_swap

CFLAGS	= -Wextra -Wall -Werror -g

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

all: $(NAME)

$(OBJECTS_PATH)/%.o: $(SOURCE_PATH)%.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJECTS_PATH) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re val
