NAME = fractol

MANDATORY = src/check_args.c src/draw.c src/hooks_main.c \
				src/iterations.c src/main.c src/utils.c src/hooks_utils.c \

OBJS = $(MANDATORY:%.c=%.o)

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

INCLUDES = -I/minilibx -Imlx_linux -O3

LIB = -Lminilibx -lmlx -lXext -lX11 -Llibft -lft -lm

RM = rm -rfv

all: $(NAME)

%.o	:	%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	make -C minilibx
	make -C libft
	$(CC) $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)


clean:
	$(RM) $(OBJS)
	make -C minilibx clean
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
