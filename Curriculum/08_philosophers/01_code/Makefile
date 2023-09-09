# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/09/09 05:09:52 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -f

DEPS = header.h

SRCS_PHILOSOHERS = main.c \
	00_check.c \
	01_info.c \
	02_fork.c \
	03_phil.c \
	04_thread.c \
	do_die.c \
	do_eat.c \
	do_sleep.c \
	do_think.c \
	routine.c \
	print.c \
	time.c
SRCS_COMMON = ft_atoi.c \
	ft_strlen.c

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
