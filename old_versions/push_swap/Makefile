# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:29:26 by pabernar          #+#    #+#              #
#    Updated: 2023/11/17 10:42:13 by pabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SRCS = main.c \
ft_stack.c ft_stack_functions.c ft_stack_helpers.c \
ft_node.c \
ft_manager.c \
ft_sort_bot.c ft_generators.c \
ft_helpers_1.c ft_helpers_2.c ft_helpers_3.c \
ft_debug.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean	
	$(MAKE)

norm:
	norminette -R CheckForbiddenSourceHeader *.h *.c
