NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = bench.c \
        compute_disorder.c  \
        main_utils.c \
        main.c \
        medium_utils.c \
        options.c \
        parser.c \
        push.c \
        put_fd.c \
        rev_rotates.c \
        rotates.c \
        sort_complex.c \
        sort_medium.c \
        sort_simple.c \
        split.c \
        swaps.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
    ar rcs $(NAME) $(OBJ)

clean:
    rm -rf $(OBJ)

fclean: clean
    rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re