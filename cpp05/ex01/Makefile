NAME = Burocracy

SRCS = src/main.cpp src/Bureaucrat.cpp src/Form.cpp

CXX = c++


RM = /bin/rm -rf
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


re: fclean all
