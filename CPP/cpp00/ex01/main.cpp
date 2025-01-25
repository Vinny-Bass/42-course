#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "utils.hpp"

int main()
{
    PhoneBook PhoneBook;
    std::string command;

    while (true)
    {
        std::cout << "\nEnter command(ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        for (size_t i = 0; i < command.length(); i++)
            command[i] = std::toupper(command[i]);

        if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (command == "ADD")
            addContact(PhoneBook);
        else if (command == "SEARCH")
            searchContact(PhoneBook);
        else
            std::cout << "Invalid command!" << std::endl;
    }
    return 0;
}
