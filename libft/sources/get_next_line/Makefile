NAME = get_next_line.a

CFLAGS = -Wall -Wextra -Werror -g

MK = mkdir -p

SOURCE_PATH =  sources/

SOURCES = \
	get_next_line.c \
	get_next_line_utils.c \

OBJECTS_PATH = objects

OBJECTS = $(addprefix $(OBJECTS_PATH)/, $(SOURCES:%.c=%.o))

all: $(NAME)

$(OBJECTS_PATH)/%.o: $(SOURCE_PATH)%.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=10 -c $< -o $@

$(NAME): $(OBJECTS)
	ar -rcT $(NAME) $?
	
clean:
	rm -rf $(OBJECTS_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all	
	
