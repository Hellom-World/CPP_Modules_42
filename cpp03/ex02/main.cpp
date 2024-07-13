#include "FragTrap.hpp"


int main() {

    // Default constructor
    ClapTrap defaultClapTrap("Oscar");
    std::cout << std::endl;
    defaultClapTrap.getName();
    defaultClapTrap.getHitPoints();
    defaultClapTrap.getEnergyPoints();
    defaultClapTrap.getAttackDamage();
    defaultClapTrap.attack("Hercules");
    defaultClapTrap.takeDamage(10);
    defaultClapTrap.beRepaired(5);


    std::cout << std::endl;
    FragTrap defaultFragTrap("Hercules");
    std::cout << std::endl;
    defaultFragTrap.getName();
    defaultFragTrap.getHitPoints();
    defaultFragTrap.getEnergyPoints();
    defaultFragTrap.getAttackDamage();
    defaultFragTrap.attack("Oscar");
    defaultFragTrap.takeDamage(10);
    defaultFragTrap.beRepaired(5);
    defaultFragTrap.highFivesGuys();


    // Destructor
    std::cout << std::endl;
    return 0;
}
