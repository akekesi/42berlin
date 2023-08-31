# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/08/31 22:14:56 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CCFLAG = -Wall -Wextra -Werror

RM = rm -f

DEPS = push_swap.h \
	get_next_line_bonus.h

SRCS_PUSH_SWAP = push_swap.c
SRCS_PUSH_SWAP_BONUS = push_swap_bonus.c
SRCS_COMMON = push_swap_test.c \
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
	check_00.c \
	ft_abs.c \
	ft_atoi.c \
	ft_is.c \
	ft_itoa.c \
	ft_putstr.c \
	ft_strlen.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c

OBJS_COMMON = $(SRCS_COMMON:.c=.o)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_PUSH_SWAP_BONUS = $(SRCS_PUSH_SWAP_BONUS:.c=.o)

%.o: %.c $(DEPS)
	$(CC) $(CCFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS_COMMON) $(OBJS_PUSH_SWAP)
	$(CC) -o $@ $^

$(NAME_BONUS): $(OBJS_COMMON) $(OBJS_PUSH_SWAP_BONUS)
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJS_COMMON)
	$(RM) $(OBJS_PUSH_SWAP)
	$(RM) $(OBJS_PUSH_SWAP_BONUS)

fclean: clean
	$(RM) ${NAME}
	$(RM) ${NAME_BONUS}

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
