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
    Weapon club = Weapon("\033[1;31mcrude spiked club\033[0m");
    HumanB jim("\033[1;20mJim\033[0m");
    jim.attack();
    jim.setWeapon(club);
    club.setType("\033[1;31msome other type of club\033[0m");
    jim.attack();
  }
  return 0;
}
