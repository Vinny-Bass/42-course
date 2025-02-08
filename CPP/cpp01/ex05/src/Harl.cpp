#include "Harl.hpp"

Harl::Harl()
{
    umap["DEBUG"] = &Harl::debug;
    umap["INFO"] = &Harl::info;
    umap["WARNING"] = &Harl::warning;
    umap["ERROR"] = &Harl::error;
}

void Harl::complain(std::string level)
{
    if (umap.find(level) != umap.end())
        (this->*umap[level])();
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
    std::cout << "[Warning] not only smoking, now you using cocaine, your chances don't look pretty good\n";
}

void Harl::error(void)
{
    std::cout << "[Error] You download tik tok, now you are officially dead\n";
}
