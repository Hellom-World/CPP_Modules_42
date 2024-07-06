#include "ClapTrap.hpp"

// Default constructor and destructor
ClapTrap::ClapTrap() : _name("Wilson"), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

// Parameterized constructor and copy constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& src) {
    *this = src;
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

// Assignation operator
ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
    return *this;
}

// Member functions
void ClapTrap::attack(std::string const& target) {
    if (_energyPoints < 1) {
        std::cout << "ClapTrap " << _name << " has not enough energy points to attack!" << std::endl;
        return;
    }
    else if (_hitPoints < 1) {
        std::cout << "ClapTrap " << _name << " has not enough hit points to attack!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
    return;
}
void ClapTrap::takeDamage(unsigned int amount) {
    if (amount > _hitPoints) {
        std::cout << "ClapTrap " << _name << " takes " << _hitPoints << " points of damage!" << std::endl;
        _hitPoints = 0;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    _hitPoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints + amount > 10) {
        std::cout << "ClapTrap " << _name << " is being repaired by " << 10 - _hitPoints << " points!" << std::endl;
        _hitPoints = 10;
        _energyPoints -= 1;
        return;
    }
    std::cout << "ClapTrap " << _name << " is being repaired by " << amount << " points!" << std::endl;
    _energyPoints -= 1;
    _hitPoints += amount;
}

// Getters
std::string ClapTrap::getName() const {
    std::cout << "ClapTrap name is " << _name << std::endl;
    return _name;
}
unsigned int ClapTrap::getHitPoints() const {
    std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points" << std::endl;
    return _hitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const {
    std::cout << "ClapTrap " << _name << " has " << _energyPoints << " energy points" << std::endl;
    return _energyPoints;
}
unsigned int ClapTrap::getAttackDamage() const {
    std::cout << "ClapTrap " << _name << " has " << _attackDamage << " attack damage" << std::endl;
    return _attackDamage;
}
