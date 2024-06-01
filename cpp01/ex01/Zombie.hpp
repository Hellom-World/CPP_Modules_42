#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cstdlib>

#define MAX_INT 2147483647 

class Zombie {
private:
    std::string _name;

public:
    Zombie() {};
    ~Zombie();

    
    void setName(std::string name);
    void announce() const;
};

//ex00
Zombie* newZombie(std::string name);
void randomChump(std::string name);

//ex01
Zombie* zombieHorde(int N, std::string name);
#endif
