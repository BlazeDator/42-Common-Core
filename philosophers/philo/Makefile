# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:29:26 by pabernar          #+#    #+#              #
#    Updated: 2023/12/19 14:58:02 by pabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3 -pthread #-fsanitize=thread
RM = rm -rf
SRCS = main.c \
philos.c forks.c \
arguments.c helpers.c \
debug.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean	
	$(MAKE)
