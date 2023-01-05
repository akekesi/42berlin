# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 20:29:56 by akekesi           #+#    #+#              #
#    Updated: 2023/01/03 22:13:47 by akekesi          ###   ########.fr        #
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
	ft_printf_check_00.c \
	ft_printf_cpy_00.c \
	ft_printf_flag_00.c \
	ft_printf_flag_01.c \
	ft_printf_flag_02.c \
	ft_printf_get_00.c \
	ft_printf_in_00.c \
	ft_printf_is_00.c \
	ft_printf_len_00.c \
	ft_printf_len_01.c \
	ft_printf_pad_00.c \
	ft_printf_print_00.c \
	ft_printf_set_00.c \
	ft_printf_to_00.c \
	ft_printf_to_01.c \
	ft_printf_to_02.c \
	ft_printf_to_03.c

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
