# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/09/07 18:22:46 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -f

DEPS = header.h

SRCS_PHILOSOHERS = main.c \
	info.c \
	fork.c \
	phil.c \
	thread.c \
	routine.c \
	do_eat.c \
	do_sleep.c \
	do_think.c \
	print.c
SRCS_COMMON = ft_atoi.c

OBJS_COMMON = $(SRCS_COMMON:.c=.o)
OBJS_PHILOSOPHERS = $(SRCS_PHILOSOHERS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_COMMON) $(OBJS_PHILOSOPHERS)
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJS_COMMON)
	$(RM) $(OBJS_PHILOSOPHERS)

fclean: clean
	$(RM) ${NAME}

re: fclean all

bonus:

.PHONY: all clean fclean re bonus
