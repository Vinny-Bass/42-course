#include <iostream>
#include <string>

char toUpper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;

    return c;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }

    int i = 1;
    while (argv[i])
    {
        std::string text = argv[i];
        for (size_t j = 0; j < text.length(); j++)
            text[j] = toUpper(text[j]);
        std::cout << text;
        i++;
    }
    std::cout << std::endl;

    return 0;
}
