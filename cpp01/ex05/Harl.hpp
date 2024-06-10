#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <cctype>

#define RESET	"\033[0m"
#define RED		"\033[1m\033[31m"
#define GREEN	"\033[1m\033[92m"
#define YELLOW	"\033[1m\033[93m"
#define BLUE	"\033[1m\033[94m"
#define PURPLE	"\033[1m\033[95m"
#define WHITE	"\033[1m\033[97m"

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

