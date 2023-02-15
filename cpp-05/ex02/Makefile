# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 14:26:19 by jtsizik           #+#    #+#              #
#    Updated: 2022/12/09 15:27:21 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = forms

HDRS =	Bureaucrat.hpp \
		AForm.hpp \
		ShrubberyCreationForm.hpp \
		RobotomyRequestForm.hpp \
		PresidentialPardonForm.hpp

OBJS =	obj/main.o \
		obj/Bureaucrat.o \
		obj/AForm.o \
		obj/ShrubberyCreationForm.o \
		obj/RobotomyRequestForm.o \
		obj/PresidentialPardonForm.o

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