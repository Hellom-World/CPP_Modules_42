NAME = Burocracy

SRCS = src/main.cpp src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp src/Intern.cpp
CXX = c++


RM = /bin/rm -rf
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean:
	$(RM) $(OBJS)
	$(RM) *_shrubbery*

fclean: clean
	$(RM) $(NAME)


re: fclean all
