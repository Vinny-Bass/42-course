#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
    _name = name;
}

void HumanA::attack(void)
{
    std::cout << _name << " attacks with their ";
    std::cout << _weapon.getType() << std::endl;
}
