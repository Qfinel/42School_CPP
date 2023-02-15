# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 16:02:58 by jtsizik           #+#    #+#              #
#    Updated: 2022/12/06 13:13:55 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

HDRS =	Animal.hpp \
		Cat.hpp \
		Dog.hpp \
		WrongAnimal.hpp \
		WrongCat.hpp

OBJS =	obj/main.o \
		obj/Animal.o \
		obj/Cat.o \
		obj/Dog.o \
		obj/WrongCat.o \
		obj/WrongAnimal.o

obj/%.o: %.cpp $(HDRS)
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