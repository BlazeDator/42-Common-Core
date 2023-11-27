# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:29:26 by pabernar          #+#    #+#              #
#    Updated: 2023/11/27 08:52:42 by pabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SRCS = main.c
SRCS_DIR = srcs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_DIR = objs/
MINILIBX = minilibx-linux/libmlx_Linux.a
MINILIBX_DIR = minilibx-linux/
MLXFLAGS = -lX11 -lXext #-lm

all: $(NAME)

$(NAME): $(OBJS_DIR) $(MINILIBX_DIR) $(LIBFT) $(MINILIBX) $(OBJS)
	cc $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p objs

$(MINILIBX_DIR):
	wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz -O minilibx
	tar -xzvf minilibx
	rm minilibx

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean	
	$(MAKE)

norm:
	norminette -R CheckForbiddenSourceHeader headers/*.h srcs/*.c
