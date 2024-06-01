#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
  {
    Weapon hammer = Weapon("\033[1;31mThor's hammer\033[0m");
    HumanA thor("\033[1;20mThor\033[0m", hammer);
    thor.attack();
    hammer.setType("\033[1;31mHammer of the GODS\033[0m");
    thor.attack();
  }
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
  return 0;
}
