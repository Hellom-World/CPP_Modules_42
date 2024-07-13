#include "ScavTrap.hpp"


// Default constructor and destructor
ScavTrap::ScavTrap() : ClapTrap(){
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _flag = 1;
    std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}

// Parameterized constructor and copy constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
    std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}

// Assignation operator
ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
    _flag = src._flag;
    return *this;
}

// Member functions
void ScavTrap::attack(std::string const& target) {
    if (_energyPoints < 1) {
        std::cout << "ScavTrap " << _name << " has not enough energy points to attack!" << std::endl;
        return;
    }
    else if (_hitPoints < 1) {
        std::cout << "ScavTrap " << _name << " has not enough hit points to attack!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
    return;
}

// Getters
std::string ScavTrap::getName() const {
    std::cout << "ScavTrap name: " << _name << std::endl;
    return _name;
}

// New member function
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode!" << std::endl;
    return;
}

