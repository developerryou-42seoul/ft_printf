# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sryou <sryou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 16:26:16 by sryou             #+#    #+#              #
#    Updated: 2022/05/20 16:32:15 by sryou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRCS = ft_printf.c \ 
		?

BONUS = 

OBJS = $(SRCS:.c=.o)

B_OBJS = $(BONUS:.c=.o)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus

all : $(NAME)
clean :
	$(RM) $(OBJECTS)
	$(RM) $(B_OBJECTS)
fclean : clean
	$(RM) $(NAME)
re : fclean all
bonus : $(B_OBJECTS)
	$(AR) $(NAME) $^