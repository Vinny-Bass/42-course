#include "utils.h"
#include <iostream>
#include <iomanip>

std::string getValidInput(const std::string &fieldName)
{
    std::string input;

    while (true)
    {
        std::cout << "Enter " << fieldName << ": ";
        std::getline(std::cin, input);

        size_t start = input.find_first_not_of(" \t");
        size_t end = input.find_last_not_of(" \t");

        if (start != std::string::npos)
            input = input.substr(start, end - start + 1);

        if (!input.empty())
            return input;

        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
}

void addContact(PhoneBook &phoneBook)
{
    Contact newContact;

    newContact.setFirstName(getValidInput("first name"));
    newContact.setLastName(getValidInput("last name"));
    newContact.setNickname(getValidInput("nickname"));
    newContact.setPhoneNumber(getValidInput("phone number"));
    newContact.setDarkestSecret(getValidInput("darkest secret"));

    phoneBook.addContact(newContact);
    std::cout << "Contact added successfully!" << std::endl;
}
