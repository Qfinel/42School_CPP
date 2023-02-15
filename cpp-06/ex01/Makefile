# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 12:05:10 by jtsizik           #+#    #+#              #
#    Updated: 2023/02/11 14:59:58 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialization

HDRS =	Data.hpp \
		Serializer.hpp

OBJS =	obj/main.o \
		obj/Serializer.o

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