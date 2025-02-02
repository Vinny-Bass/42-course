#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *horde = zombieHorde(N, "Walker");

    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }

    for (int i = 0; i < N; i++)
    {
        horde[i].~Zombie();
    }

    char *memory = reinterpret_cast<char *>(horde);
    delete[] memory;

    return 0;
}
