# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdannay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 10:22:09 by gdannay           #+#    #+#              #
#    Updated: 2018/03/27 15:29:11 by gdannay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_nm

SRCS	=	./srcs/main.c			\
			./srcs/symbols_64.c		\
			./srcs/symbols_32.c		\
			./srcs/output.c			\
			./srcs/swap_bytes.c		\
			./srcs/handler_ar.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I./includes

LDFLAGS	=	../libft/libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C ../libft
			$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
			
%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAGS)

clean	:	
			make clean -C ../libft
			rm -rf $(OBJS)

fclean	:	
			make fclean -C ../libft
			rm -rf $(OBJS)
			rm -rf $(NAME)

re		:	fclean all
