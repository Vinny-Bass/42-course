#include "utils.hpp"

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

std::string formatColumn(const std::string &text, size_t width)
{
    if (text.length() > width)
        return text.substr(0, width - 1) + ".";

    return std::string(width - text.length(), ' ') + text;
}

void displayContactList(const PhoneBook &phoneBook, std::ostream &out)
{
    out << "|" << formatColumn("INDEX", 10)
        << "|" << formatColumn("FIRST NAME", 10)
        << "|" << formatColumn("LAST NAME", 10)
        << "|" << formatColumn("NICKNAME", 10)
        << "|" << std::endl;

    out << std::string(44, '-') << std::endl;

    for (int i = 0; i < phoneBook.getSize(); i++)
    {
        Contact contact = phoneBook.getContact(i);
        std::stringstream ss;
        ss << i;
        out << "|" << formatColumn(ss.str(), 10)
            << "|" << formatColumn(contact.getFirstName(), 10)
            << "|" << formatColumn(contact.getLastName(), 10)
            << "|" << formatColumn(contact.getNickname(), 10)
            << "|" << std::endl;
    }
}

void searchContact(const PhoneBook &phoneBook)
{
    if (phoneBook.getSize() == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    displayContactList(phoneBook);

    std::cout << "\nEnter index to display: ";
    std::string input;
    std::getline(std::cin, input);

    try
    {
        std::istringstream iss(input);
        int index;
        if (!(iss >> index))
            throw "Invalid index!";
        if (index >= 0 && index < phoneBook.getSize())
        {
            Contact contact = phoneBook.getContact(index);
            std::cout << "\nContact details:" << std::endl;
            std::cout << "First name: " << contact.getFirstName() << std::endl;
            std::cout << "Last name: " << contact.getLastName() << std::endl;
            std::cout << "Nickname: " << contact.getNickname() << std::endl;
            std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
            std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
        }
        else
            std::cout << "Invalid index!" << std::endl;
    }
    catch (...)
    {
        std::cout << "Invalid input!" << std::endl;
    }
}
