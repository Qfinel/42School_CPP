# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 18:26:20 by jtsizik           #+#    #+#              #
#    Updated: 2022/12/01 16:10:14 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence

HDRS =	HumanA.hpp \
		HumanB.hpp \
		Weapon.hpp

OBJS =	obj/main.o \
		obj/HumanA.o \
		obj/HumanB.o \
		obj/Weapon.o

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