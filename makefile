NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS =	error_free.c main.c rotate.c ft_split.c push.c sort.c reverse_rotate.c\
		ft_strlcpy.c push_swap_init.c stack_init.c ft_strlen.c swap.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

mk : all clean

.PHONY : clean