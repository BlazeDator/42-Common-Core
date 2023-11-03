# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 12:04:58 by pabernar          #+#    #+#              #
#    Updated: 2023/11/03 14:39:47 by pabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_typefinder.c ft_putnbr.c \
ft_puthex.c ft_putpointer.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) #$(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

