NAME = push_swap

#BONUS_NAME = pipex_bonus

#LIBFT = libs/libft/libft.a

#LIBFT_PATH = libs/libft/

#GET_NEXT_LINE = libs/get_next_line/get_next_line.a

#GET_NEXT_LINE_PATH = libs/get_next_line/

CFLAGS	= -Wextra -Wall -Werror -g

HEADERS	= -I ./includes/

MK = mkdir -p

#VAL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes \
	--trace-children=yes --trace-children-skip=*/bin/*,*/sbin/* \

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
#BONUS_SRCS	= 

OBJECTS_PATH = objects

#BONUS_OBJECTS_PATH = bonus_objects

OBJS = $(addprefix $(OBJECTS_PATH)/, $(SRCS:%.c=%.o))

#BONUS_OBJS	= $(addprefix $(BONUS_OBJECTS_PATH)/, $(BONUS_SRCS:%.c=%.o))

all: $(NAME)

#$(LIBFT):
#	make -C $(LIBFT_PATH)

#$(GET_NEXT_LINE):
#	make -C $(GET_NEXT_LINE_PATH)

$(OBJECTS_PATH)/%.o: $(SOURCE_PATH)%.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

#$(BONUS_OBJECTS_PATH)/%.o: $(BONUS_SOURCE_PATH)%.c
#	$(MK) $(@D)
#	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(HEADERS) -o $(NAME)

#$(BONUS_NAME): $(BONUS_OBJS)
#	$(CC) $(BONUS_OBJS) $(LIBFT) $(GET_NEXT_LINE) $(HEADERS) -o $(BONUS_NAME)

clean:
	rm -rf $(OBJECTS_PATH) 
#	make clean -C $(LIBFT_PATH)
#	make clean -C $(GET_NEXT_LINE_PATH)

fclean: clean
	rm -rf $(NAME)
#	make fclean -C $(LIBFT_PATH)
#	make fclean -C $(GET_NEXT_LINE_PATH)

#bonus: $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re val
