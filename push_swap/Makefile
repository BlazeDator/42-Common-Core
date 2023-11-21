# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:29:26 by pabernar          #+#    #+#              #
#    Updated: 2023/11/21 11:35:26 by pabernar         ###   ########.fr        #
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
ft_algorithm.c ft_targets.c ft_push_cost_one.c \
ft_moves_phase_one.c ft_moves_phase_two.c ft_moves_phase_three.c \
ft_helpers.c ft_math.c\
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
