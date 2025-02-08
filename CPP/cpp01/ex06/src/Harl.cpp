#include "Harl.hpp"

Harl::Harl()
{
    levels[0].name = "DEBUG";
    levels[0].func = &Harl::debug;

    levels[1].name = "INFO";
    levels[1].func = &Harl::info;

    levels[2].name = "WARNING";
    levels[2].func = &Harl::warning;

    levels[3].name = "ERROR";
    levels[3].func = &Harl::error;
}

void Harl::complain(std::string level)
{
    int start_level = -1;

    for (int i = 0; i < NUM_LEVELS; i++)
    {
        if (levels[i].name == level)
        {
            start_level = i;
            break;
        }
    }

    if (start_level == -1)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }

    for (int i = start_level; i < NUM_LEVELS; i++)
    {
        (this->*levels[i].func)();
    }
}

void Harl::debug(void)
{
    std::cout << "[DEBUG] You just born and probably will live a happy life\n";
}

void Harl::info(void)
{
    std::cout << "[INFO] You start to smoke, you can still be happy, but probably will have cancer\n";
}

void Harl::warning(void)
{
    std::cout << "[WARNING] not only smoking, now you using cocaine, your chances don't look pretty good\n";
}

void Harl::error(void)
{
    std::cout << "[ERROR] You download tik tok, now you are officially dead\n";
}
