NAME = bst.a

CFLAGS	= -Wextra -Wall -Werror

HEADERS	= -Iincludes

MK = mkdir -p

SOURCE_PATH = sources/

SRCS	= \
			create_node.c \
			check_node.c \
			min_max.c \
			traversal.c \
			breadth.c \
			del_utils.c

OBJECTS_PATH = objects

OBJS = $(addprefix $(OBJECTS_PATH)/, $(SRCS:%.c=%.o))

all: $(NAME)

$(OBJECTS_PATH)/%.o: $(SOURCE_PATH)%.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	ar -rcT $(NAME) $?

clean:
	rm -rf $(OBJECTS_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 