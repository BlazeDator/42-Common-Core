# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:29:26 by pabernar          #+#    #+#              #
#    Updated: 2024/01/04 15:29:19 by pabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3 -pthread #-fsanitize=thread
RM = rm -rf
SRCS = main.c \
philos.c philos_extra.c\
forks.c time.c \
arguments.c helpers.c helpers_extra.c \
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

valgrind:
	valgrind --fair-sched=yes ./philo 3 1200 200 200 4
