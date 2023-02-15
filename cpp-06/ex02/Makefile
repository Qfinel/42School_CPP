# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 12:28:29 by jtsizik           #+#    #+#              #
#    Updated: 2022/12/10 12:30:01 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = realtype

HDRS =	Base.hpp \
		A.hpp \
		B.hpp \
		C.hpp

OBJS =	obj/main.o \
		obj/Base.o \
		obj/A.o \
		obj/B.o \
		obj/C.o

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