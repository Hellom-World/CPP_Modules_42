# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 13:21:38 by heolivei          #+#    #+#              #
#    Updated: 2024/04/25 13:21:44 by heolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

CXX = c++

RM = /bin/rm -rf
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -fsanitize=address

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

doAll: all
	make -s -C ../ex01

fcleanAll: fclean
	make fclean -s -C ../ex01

.PHONY : all clean fclean re
