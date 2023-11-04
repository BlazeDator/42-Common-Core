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

NAME = server client
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SERVER = server
SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT = client
CLIENT_SRCS = client.c client_utils.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(SERVER_OBJS) $(CLIENT_OBJS)
	cc $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT) 
	cc $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT)	

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean	
	$(MAKE)
