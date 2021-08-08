# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruth-ra <aruth-ra@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 20:55:33 by aruth-ra          #+#    #+#              #
#    Updated: 2021/08/08 13:59:03 by aruth-ra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=  libftprintf.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

AR		= ar rcs

HEADERS = ft_printf.h

FILES 	= ft_printf.c ft_printf_utils.c ft_put_types.c ft_unsigned_utils.c ft_pointer_utils.c

.c.o:
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

OBJECTS		= $(FILES:.c=.o)

$(NAME):
				@$(CC) $(CFLAGS) -c $(FILES)
				@$(AR) $(NAME) $(OBJECTS)
				@echo "Printf created!"

all:		$(NAME)

clean:
			@$(RM) $(OBJECTS)
			@echo "Clean"

fclean:		clean
			@$(RM) $(NAME)
			@echo "Printf removed"

re:			fclean all

.PHONY: all clean fclean re