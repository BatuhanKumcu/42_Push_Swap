NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
			  check_sorted.c \
			  error_free.c \
			  parse_args.c \
			  parse_checks.c \
			  parse_flags.c \
			  parse_values.c \
			  rank_values.c \
			  stack_core.c \
			  utils_mem.c \
			  utils_str.c \
			  utils_write.c
OBJS		= $(SRCS:.c=.o)

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
