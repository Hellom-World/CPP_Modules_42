#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    // Atributos
    private:
        int     index;
		int     contactsCount;
        Contact contacts[8];
    public:
        // Construtores e Destrutores
        PhoneBook();
        ~PhoneBook() { };
        // Métodos
        void addContact();
        void searchContact();
        void printContact();
        void printContacts();

        //getters

        int getContactsCount(void);
};

#endif