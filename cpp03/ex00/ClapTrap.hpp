#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    public:
        // Default constructor and destructor
        ClapTrap();
        ~ClapTrap();

        // Parameterized constructor and copy constructor
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& src);

        // Assignation operator
        ClapTrap& operator=(const ClapTrap& src);

        // Member functions
        void attack(std::string const& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        // Getters
        std::string getName() const;
        unsigned int getHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage() const;

};

#endif
