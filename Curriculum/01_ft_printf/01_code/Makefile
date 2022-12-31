# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 20:29:56 by akekesi           #+#    #+#              #
#    Updated: 2022/12/31 21:44:03 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CCFLAG = -Wall -Wextra -Werror

AR = ar
ARFLAG = crs

RM = rm -f

DEPS = ft_printf.h

SRCS = ft_printf.c \
	ft_printf_00.c \
	ft_printf_01.c \
	ft_printf_02.c \
	ft_printf_03.c \
	ft_printf_04.c

SRCS_BONUS = 

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CCFLAG) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAG) $@ $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) ${NAME}

re: fclean all

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAG) $(NAME) $^

.PHONY: all clean fclean re bonus
