#include "ClapTrap.hpp"

int main() {

    // Test with default constructor
    ClapTrap Clap;
    // Test with parameterized constructor
    ClapTrap clapTrapCopy(Clap);
    // Test with copy constructor
    ClapTrap clapTrapCopy2 = Clap;

    // Test with member functions forbidden by the subject

    std::cout << std::endl;
    std::cout << "TEST ATTACK WITH <N> HITPONTS" << std::endl;
    Clap.getHitPoints();
    Clap.getEnergyPoints();
    Clap.attack("GHOST");
    std::cout << std::endl;
    Clap.takeDamage(20);
    Clap.getHitPoints();
    Clap.getEnergyPoints();
    Clap.attack("GHOST");
    std::cout << std::endl;
    Clap.beRepaired(5);
    Clap.getHitPoints();
    Clap.getEnergyPoints();
    Clap.attack("GHOST");
    std::cout << std::endl;
    Clap.getHitPoints();
    Clap.getEnergyPoints();
    Clap.attack("GHOST");
    Clap.attack("GHOST");

    std::cout << std::endl;
    std::cout << "TEST ATTACK WITH <N> ENERGYPOINTS" << std::endl;
    Clap.getHitPoints();
    Clap.getEnergyPoints();
    Clap.attack("GHOST");
    std::cout << std::endl;
    Clap.attack("GHOST");
    Clap.attack("GHOST");
    Clap.attack("GHOST");
    Clap.attack("GHOST");
    Clap.getEnergyPoints();


    // Destructor
    std::cout << std::endl;
    return 0;
}
