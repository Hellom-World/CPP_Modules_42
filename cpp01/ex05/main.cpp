#include "Harl.hpp"

int main(void) {
  Harl harl;

  harl.complain("DEBUG");
  harl.complain("info");
  harl.complain("warning");
  harl.complain("error");
  harl.complain("not a valid level");

  return 0;
}
