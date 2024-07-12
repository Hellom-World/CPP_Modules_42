#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


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
    ScavTrap defaultScavTrap("Hercules");
    std::cout << std::endl;
    defaultScavTrap.getName();
    defaultScavTrap.getHitPoints();
    defaultScavTrap.getEnergyPoints();
    defaultScavTrap.getAttackDamage();
    defaultScavTrap.attack("Oscar");
    defaultScavTrap.takeDamage(10);
    defaultScavTrap.beRepaired(5);
    defaultScavTrap.guardGate();



    // Destructor
    std::cout << std::endl;
    return 0;
}
