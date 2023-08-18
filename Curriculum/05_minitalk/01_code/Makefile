# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/08/18 18:36:57 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server # only one NAME
NAME_C = client # only one NAME

CC = cc
CCFLAG = -Wall -Wextra -Werror

RM = rm -f

DEPS = minitalk.h

SRCS_S = server.c \
	itoa_pos.c \
	putstr.c
SRCS_C = client.c \
	itoa_pos.c \
	putstr.c

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
