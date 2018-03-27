# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdannay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 15:57:12 by gdannay           #+#    #+#              #
#    Updated: 2018/03/27 16:00:25 by gdannay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_NM			=	ft_nm

NAME_OTOOL		=	ft_otool

SRCS_OTOOL		=	./otool/srcs/main.c				\
					./otool/srcs/symbols_64.c		\
					./otool/srcs/symbols_32.c		\
					./otool/srcs/swap_bytes.c		\
					./otool/srcs/output.c			\
					./otool/srcs/handler_ar.c

SRCS_NM			=	./nm/srcs/main.c			\
					./nm/srcs/symbols_64.c		\
					./nm/srcs/symbols_32.c		\
					./nm/srcs/output.c			\
					./nm/srcs/swap_bytes.c		\
					./nm/srcs/handler_ar.c

OBJS_OTOOL		=	$(SRCS_OTOOL:.c=.o)

OBJS_NM			=	$(SRCS_NM:.c=.o)

CFLAGS			=	-Wall -Wextra -Werror -I./otool/includes -I./nm/includes

LDFLAGS			=	libft/libft.a

CC				=	gcc

all				:	$(NAME_NM) $(NAME_OTOOL)

$(NAME_NM)		:	$(OBJS_NM)
					make -C libft
					$(CC) $(OBJS_NM) $(LDFLAGS) -o $(NAME_NM)

$(NAME_OTOOL)	:	$(OBJS_OTOOL)
					make -C libft
					$(CC) $(OBJS_OTOOL) $(LDFLAGS) -o $(NAME_OTOOL)

%.o				:	%.c
					$(CC) -o $@ -c $< $(CFLAGS)

clean			:
					make clean -C libft
					rm -rf $(OBJS_NM)
					rm -rf $(OBJS_OTOOL)

fclean			:
					make fclean -C libft
					rm -rf $(OBJS_NM)
					rm -rf $(OBJS_OTOOL)
					rm -rf $(NAME_NM)
					rm -rf $(NAME_OTOOL)

re				:	fclean all
