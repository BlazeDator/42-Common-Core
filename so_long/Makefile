# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:29:26 by pabernar          #+#    #+#              #
#    Updated: 2023/11/24 10:21:06 by pabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-lm
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SRCS = main.c
SRCS_DIR = srcs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_DIR = objs/

all: $(NAME)

$(NAME): $(OBJS_DIR) $(LIBFT) $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) 

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p objs

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean	
	$(MAKE)

norm:
	norminette -R CheckForbiddenSourceHeader headers/*.h srcs/*.c
