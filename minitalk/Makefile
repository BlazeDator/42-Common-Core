# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:29:26 by pabernar          #+#    #+#              #
#    Updated: 2023/11/03 16:05:46 by pabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk 
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT_DIR = libft/
LIBFT_LIB = libft.a
SRC = server.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(MAKE) -C $(LIBFT_DIR) 
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)$(LIBFT_LIB)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean	
	$(MAKE) all
