# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/09/06 17:38:25 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CCFLAG = -Wall -Wextra -Werror

RM = rm -f

DEPS = header.h

SRCS_PHILOSOHERS = main.c \
	fork.c \
	phil.c \
	thread.c \
	info.c
SRCS_COMMON = ft_atoi.c

OBJS_COMMON = $(SRCS_COMMON:.c=.o)
OBJS_PHILOSOPHERS = $(SRCS_PHILOSOHERS:.c=.o)

%.o: %.c $(DEPS)
	$(CC) $(CCFLAG) -c $< -o $@

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
