# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoares- <gsoares-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 00:55:55 by gsoares-          #+#    #+#              #
#    Updated: 2021/04/03 01:51:39 by gsoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
FLAGS	= -Wall -Werror -Wextra
CREATE	= ar crs
NAME	= libftprintf.a
LIB		= ft_printf.h

FUNCS	= ft_printf.c ft_print_utils.c ft_print_utils_2.c ft_itoa.c

all:		$(NAME)

$(NAME):	$(FUNCS:.c=.o) $(LIB)
			$(CREATE) $(NAME) $(FUNCS:.c=.o)

clean:
			rm -f $(FUNCS:.c=.o)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

so:			$(FUNCS:.c=.o) $(LIB)
			$(CC) -shared -fPIC -Wl,-soname,libftprintf.so -o libftprintf.so $(FUNCS:.c=.o)

.PHONY: all clean fclean re so