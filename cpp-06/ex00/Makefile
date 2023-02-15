# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 16:07:39 by jtsizik           #+#    #+#              #
#    Updated: 2023/02/11 14:01:45 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

HDRS =	ScalarConverter.hpp

OBJS =	obj/main.o \
		obj/ScalarConverter.o

obj/%.o: %.cpp
	c++ -c -Wall -Wextra -Werror -std=c++98 $< -o $@

$(NAME): obj $(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 $(OBJS) -o $(NAME)

all: $(NAME)

obj:
	mkdir obj

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all