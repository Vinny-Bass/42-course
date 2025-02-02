#include "Zombie.hpp"
#include <sstream>

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;

    char *memory = new char[sizeof(Zombie) * N];
    Zombie *horde = reinterpret_cast<Zombie *>(memory);

    for (int i = 0; i < N; i++)
    {
        std::stringstream sstm;
        sstm << i << ":" << name;
        new (&horde[i]) Zombie(sstm.str());
    }

    return horde;
}
