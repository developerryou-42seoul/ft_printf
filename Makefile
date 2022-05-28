# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sryou <sryou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 16:26:16 by sryou             #+#    #+#              #
#    Updated: 2022/05/28 13:23:25 by sryou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT		= Libft
LIBFT_LIB	= libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRCS = ft_printf.c \
		interpret.c \
		make1.c \
		make2.c \
		utils.c \
		process.c

BONUS = ft_printf_bonus.c

OBJS = $(SRCS:.c=.o)

B_OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus

all : $(NAME)
clean :
	make fclean -C $(LIBFT)/
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
fclean : clean
	$(RM) $(NAME)
re : fclean all
bonus : $(B_OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $^
test : bonus
	$(CC) $(CFLAGS) main.c -L ./ -l ftprintf -o test
	./test
