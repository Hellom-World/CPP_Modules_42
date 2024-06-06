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
    Weapon club = Weapon("\033[1;31mSpiked Club\033[0m");
    HumanB jim("\033[1;20mJim\033[0m");
    jim.setWeapon(club);
    jim.attack();
    club.setType("\033[1;31mMedieval Club\033[0m");
    jim.attack();
  }
  return 0;
}
