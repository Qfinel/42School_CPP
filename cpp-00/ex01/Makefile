# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 18:06:09 by jtsizik           #+#    #+#              #
#    Updated: 2022/11/30 11:38:16 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

HDRS =	Contact.hpp \
		PhoneBook.hpp

OBJS =	obj/main.o \
		obj/Contact.o \
		obj/PhoneBook.o

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