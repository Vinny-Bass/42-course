#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

void PhoneBook::addContact(const Contact &contact)
{
    contacts[currentIndex] = contact;

    currentIndex = (currentIndex + 1) % 8;

    if (totalContacts < 8)
        totalContacts++;
}

Contact PhoneBook::getContact(int index) const
{
    if (index >= 0 && index < totalContacts)
    {
        return contacts[index];
    }

    return Contact();
}

int PhoneBook::getSize() const
{
    return totalContacts;
}
