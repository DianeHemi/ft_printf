# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/08 18:23:17 by dchampda          #+#    #+#              #
#    Updated: 2020/05/08 18:36:01 by dchampda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFT		=	./libft/libft.a
INCLUDES	=	-I./includes

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRCS		=	./srcs/ft_printf.c \
				./srcs/ft_conv_base.c \
				./srcs/ft_parsing.c \
				./srcs/ft_treat_char.c \
				./srcs/ft_treat_flags.c \
				./srcs/ft_treat_hexa.c \
				./srcs/ft_treat_int.c \
				./srcs/ft_treat_perct.c \
				./srcs/ft_treat_ptr.c \
				./srcs/ft_treat_str.c \
				./srcs/ft_treat_uint.c \
				./srcs/ft_treat_width.c \
				./srcs/ft_uitoa.c

OBJS		=	${SRCS:.c=.o}

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} $(INCLUDES) -g -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	make -C ./libft
	cp libft/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	make clean -C ./libft
	${RM} ${OBJS}

fclean: clean
	make fclean -C ./libft
	${RM} ${NAME}

re:	fclean all

.PHONY : all clean fclean re
