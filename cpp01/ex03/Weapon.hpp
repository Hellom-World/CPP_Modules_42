#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <string>
# include <iostream>
# include <cctype>

class Weapon {
    private:
        std::string _type;
    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string &getType() const;
        void setType(std::string type);
};
#endif
