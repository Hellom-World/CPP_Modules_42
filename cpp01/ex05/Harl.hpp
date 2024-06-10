#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <cctype>

#define RESET	"\033[0m"
#define RED		"\033[1m\033[31m"
#define GREEN	"\033[1m\033[32m"
#define YELLOW	"\033[1m\033[33m"
#define BLUE	"\033[1m\033[34m"
#define PURPLE	"\033[1m\033[35m"
#define WHITE	"\033[1m\033[37m"

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif

