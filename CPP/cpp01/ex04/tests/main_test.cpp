#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: ./tester <filename> <s1>\n";
        return 0;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];

    std::string line;
    std::ifstream Content(filename.c_str());
    if (!Content.good())
    {
        std::cout << "File do not exists\n";
        return 0;
    }

    std::string buffer;
    int lineIndex = 0;
    while (std::getline(Content, line))
    {
        size_t wordIndex = line.find(s1);
        if (wordIndex != std::string::npos)
        {
            std::cout << "Error, " + s1 + " found in ";
            std::cout << "line: " << lineIndex << " index: ";
            std::cout << wordIndex << std::endl;
            break;
        }
    }
    Content.close();

    return 0;
}
