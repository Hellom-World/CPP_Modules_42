#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>

class Contact {
    // Atributos
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        // Construtores e Destrutores
        Contact() { };
        ~Contact(){ };

        //setters
        void    setFirstName(std::string firstName);
        void	setLastName(std::string lastName);
        void	setNickName(std::string nickName);
        void	setPhoneNumber(std::string phoneNumber);
        void	setDarkestSecret(std::string darkestSecret);

        //getters
        std::string		getFirstName(void);
        std::string		getLastName(void);
        std::string		getNickName(void);
        std::string		getPhoneNumber(void);
        std::string		getDarkestSecret(void);
};

void printMenu();

#endif