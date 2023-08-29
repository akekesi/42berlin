# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/08/29 21:54:16 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CCFLAG = -Wall -Wextra -Werror

RM = rm -f

DEPS = push_swap.h

SRCS = push_swap.c \
	llist_00.c \
	llist_01.c \
	llist_02.c \
	llist_03.c \
	llist_04.c \
	moves_00.c \
	moves_01.c \
	moves_02.c \
	moves_03.c \
	moves_04.c \
	sort_00.c \
	ft_abs.c \
	ft_atoi.c \
	ft_is.c \
	ft_itoa.c \
	ft_putstr.c \
	push_swap_test.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(DEPS)
	$(CC) $(CCFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ${NAME}

re: fclean all

bonus:

.PHONY: all clean fclean re bonus
