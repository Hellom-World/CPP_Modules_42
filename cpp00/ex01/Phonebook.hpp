/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:23:54 by heolivei          #+#    #+#             */
/*   Updated: 2024/04/25 13:23:58 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    // Atributos
    private:
        int     index;
		int     contactsCount;
        int     nextIndexToReplace;
        int     maxContacts;
        Contact contacts[8];
    public:
        // Construtores e Destrutores
        PhoneBook();
        ~PhoneBook() { };
        // Métodos
        void addContact();
        void searchContact();
        void printContacts();

        //getters

        int getContactsCount(void);
        int getNextIndexToReplace(void);
        int getMaxContacts(void);

        //setters  
        void setContactsCount(int contactsCount);
        void setNextIndexToReplace(int nextIndexToReplace);
};

#endif
