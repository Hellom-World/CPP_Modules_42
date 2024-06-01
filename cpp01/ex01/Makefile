
NAME = zombie

SRCS = main.cpp Zombie.cpp newZombie.cpp zombieHorde.cpp

CXX = c++


RM = /bin/rm -rf
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -fsanitize=address

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
