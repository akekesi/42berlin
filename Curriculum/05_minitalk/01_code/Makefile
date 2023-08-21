# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/08/21 22:17:49 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
NAME_S_BONUS = server_bonus
NAME_C_BONUS = client_bonus

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

$(NAME_S_BONUS): $(OBJS_S)
	$(CC) -o $@ $^

$(NAME_C_BONUS): $(OBJS_C)
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJS_S)
	$(RM) $(OBJS_C)

fclean: clean
	$(RM) ${NAME_S}
	$(RM) ${NAME_C}
	$(RM) ${NAME_S_BONUS}
	$(RM) ${NAME_C_BONUS}

re: fclean all

bonus:	$(NAME_S_BONUS) $(NAME_C_BONUS)

.PHONY: all clean fclean re bonus
