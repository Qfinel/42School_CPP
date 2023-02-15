# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 18:26:20 by jtsizik           #+#    #+#              #
#    Updated: 2022/11/30 18:40:29 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

HDRS =	Zombie.hpp

OBJS =	obj/newZombie.o \
		obj/main.o \
		obj/randomChump.o \
		obj/Zombie.o

obj/%.o: %.cpp $(HDRS)
	c++ -c -Wall -Wextra -Werror -std=c++98 $< -o $@ -I $(HDRS)

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