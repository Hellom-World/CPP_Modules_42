#include "ScavTrap.hpp"


// Default constructor and destructor
ScavTrap::ScavTrap() : ClapTrap(){
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
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
void ScavTrap::takeDamage(unsigned int amount) {
    if (amount > _hitPoints) {
        std::cout << "ScavTrap " << _name << " takes " << _hitPoints << " points of damage!" << std::endl;
        _hitPoints = 0;
        return;
    }
    std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    _hitPoints -= amount;
}
void ScavTrap::beRepaired(unsigned int amount) {
    if (_hitPoints + amount > 100) {
        std::cout << "ScavTrap " << _name << " is being repaired by " << 100 - _hitPoints << " points!" << std::endl;
        _hitPoints = 100;
        _energyPoints -= 1;
        return;
    }
    std::cout << "ScavTrap " << _name << " is being repaired by " << amount << " points!" << std::endl;
    _energyPoints -= 1;
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

