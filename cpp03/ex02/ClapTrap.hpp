#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    private:
    protected:
        std::string     _name;
        unsigned int	_hitPoints;
        unsigned int	_energyPoints;
        unsigned int	_attackDamage;
        int             _flag;

    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& copy);

        ClapTrap&	operator=(const ClapTrap& other);

        void	attack(std::string const& target);
        void	takeDamage(unsigned int amount);
        void	beRepaired(unsigned int amount);

        std::string	getName() const;
        unsigned int			getHitPoints() const;
        unsigned int			getEnergyPoints() const;
        unsigned int			getAttackDamage() const;
};

#endif
