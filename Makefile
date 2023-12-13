# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relamine <relamine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 13:16:57 by relamine          #+#    #+#              #
#    Updated: 2023/12/13 13:41:43 by relamine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

RM = rm -f

%.o : %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

all : $(NAME)

clean :
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re : fclean all