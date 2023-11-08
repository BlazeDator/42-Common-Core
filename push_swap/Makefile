# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:29:26 by pabernar          #+#    #+#              #
#    Updated: 2023/11/08 12:49:32 by pabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SRCS = main.c \
ft_stack_new.c ft_stack_add_front.c ft_stack_add_back.c ft_stack_size.c \
ft_stack_copy.c ft_stack_clear.c \
ft_stack_swap.c ft_stack_push.c ft_stack_rotate.c \
ft_stack_sorter.c
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
