#include "Zombie.hpp"

int main(void)
{
    Zombie *heap_zombie = newZombie("Heapy"); // this one will live until delete or program finishes, use when needs to pass arround
    heap_zombie->announce();

    randomChump("Stacky"); // this one dies after the function scope, use only when it is needed in the scope

    delete heap_zombie;
    return 0;
}
