# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 16:02:58 by jtsizik           #+#    #+#              #
#    Updated: 2022/12/07 12:05:40 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

HDRS =	Bureaucrat.hpp

OBJS =	obj/main.o \
		obj/Bureaucrat.o

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