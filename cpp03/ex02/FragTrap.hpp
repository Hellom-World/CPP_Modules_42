#ifndef FragTrap_HPP
# define FragTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        ~FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);

        FragTrap&	operator=(const FragTrap& other);

        void	attack(std::string const& target);

        std::string	getName() const;
        void	 highFivesGuys(void);


};

#endif
