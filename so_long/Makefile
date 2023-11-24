# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:29:26 by pabernar          #+#    #+#              #
#    Updated: 2023/11/24 09:45:43 by pabernar         ###   ########.fr        #
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
OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_DIR)$(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS_DIR)$(OBJS) $(LIBFT) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) 

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)$(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean	
	$(MAKE)

norm:
	norminette -R CheckForbiddenSourceHeader headers/*.h srcs/*.c
