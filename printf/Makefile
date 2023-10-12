# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 12:04:58 by pabernar          #+#    #+#              #
#    Updated: 2023/10/12 11:25:40 by pabernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = 
OBJS = $(SRC:.c=.o)

#SRCBONUS =

#OBJSBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

#bonus: $(OBJS) $(OBJSBONUS)
#	ar rc $(NAME) $(OBJS) $(OBJSBONUS)	

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o

clean:
	$(RM) $(OBJS) #$(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
