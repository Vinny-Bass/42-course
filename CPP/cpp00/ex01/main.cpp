#include <iostream>
#include <string>
#include "PhoneBook.h"

int main()
{
    PhoneBook PhoneBook;
    std::string command;

    while (true)
    {
        std::cout << "\nEnter command(ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        for (char &c : command)
        {
            c = std::toupper(c);
        }

        if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (command == "ADD")
            addContact(PhoneBook);
        else if (command == "SEARCH")
            searchContact(phoneBook);
        else
            std::cout << "Invalid command!" << std::endl;
    }
    return 0;
}
