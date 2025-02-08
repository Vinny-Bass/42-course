#include <iostream>
#include <fstream>
#include <string>

std::string ft_replace(std::string buffer, std::string s1, std::string s2)
{
    size_t erase_len = s1.length();
    size_t replace_len = s2.length();
    size_t pos_search = 0;

    pos_search = buffer.find(s1);
    while (pos_search != std::string::npos)
    {
        buffer.erase(pos_search, erase_len);
        buffer.insert(pos_search, s2);
        pos_search = buffer.find(s1, pos_search + replace_len);
    }
    return (buffer);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: ./sed_is_for_losers <filename> <s1> <s2>\n";
        return 0;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::string line;
    std::ifstream Content(filename.c_str());
    if (!Content.good())
    {
        std::cout << "File do not exists\n";
        return 0;
    }

    std::ofstream outfile;
    std::string newFile = filename + ".replace";
    outfile.open(newFile.c_str());
    if (!outfile.is_open())
    {
        std::cout << "Can't create a new file\n";
        return 0;
    }

    std::string buffer;
    while (std::getline(Content, line))
    {
        buffer = ft_replace(line, s1, s2);
        outfile << buffer;
        if (Content.peek() != EOF)
            outfile << std::endl;
    }
    Content.close();
    outfile.close();

    return 0;
}
