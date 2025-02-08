#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>
#include <map>

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    struct ComplaintLevel
    {
        std::string name;
        void (Harl::*func)(void);
    };

public:
    Harl();
    void complain(std::string level);
};

#endif
