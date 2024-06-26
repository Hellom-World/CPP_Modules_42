/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:23:01 by heolivei          #+#    #+#             */
/*   Updated: 2024/04/25 13:23:05 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <limits>
# include <iomanip>
# include <cstdlib>
# include <csignal>

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
void signalHandler(int sig);
bool validate_input(const std::string& input, int flag);
bool get_valid_input(std::istream& in, std::string& input, int flag);
std::string formatColumn(const std::string& text);
int my_stoi(const std::string& s);

#endif
