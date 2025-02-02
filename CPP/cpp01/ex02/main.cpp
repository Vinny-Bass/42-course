#include <string>
#include <iostream>

int main(void)
{
    std::string phrase = "HI THIS IS BRAIN";
    std::string *stringPTR = &phrase;
    std::string &stringREF = phrase;

    std::cout << &phrase << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << phrase << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}
