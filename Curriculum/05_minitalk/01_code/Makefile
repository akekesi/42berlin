# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/08/20 20:03:19 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server # only one NAME
NAME_C = client # only one NAME

CC = cc
CCFLAG = -Wall -Wextra -Werror

RM = rm -f

DEPS = minitalk.h

SRCS_S = server.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_putstr.c \
	ft_is.c
SRCS_C = client.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_putstr.c \
	ft_is.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

%.o: %.c $(DEPS)
	$(CC) $(CCFLAG) -c $< -o $@

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) -o $@ $^

$(NAME_C): $(OBJS_C)
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJS_S)
	$(RM) $(OBJS_C)

fclean: clean
	$(RM) ${NAME_S}
	$(RM) ${NAME_C}

re: fclean all

bonus:

.PHONY: all clean fclean re bonus
