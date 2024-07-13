#include "FragTrap.hpp"


// Default constructor and destructor
FragTrap::FragTrap() : ClapTrap(){
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has been created" << std::endl;
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " has been destroyed" << std::endl;
}

// Parameterized constructor and copy constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has been created" << std::endl;
}
FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
    std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

// Assignation operator
FragTrap& FragTrap::operator=(const FragTrap& src) {
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
    return *this;
}

// Member functions
void FragTrap::attack(std::string const& target) {
    if (_energyPoints < 1) {
        std::cout << "FragTrap " << _name << " has not enough energy points to attack!" << std::endl;
        return;
    }
    else if (_hitPoints < 1) {
        std::cout << "FragTrap " << _name << " has not enough hit points to attack!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
    return;
}

// Getters
std::string FragTrap::getName() const {
    std::cout << "FragTrap name: " << _name << std::endl;
    return _name;
}

// New member function
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
    return;
}

