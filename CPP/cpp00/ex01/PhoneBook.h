#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

class PhoneBook
{
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;

public:
    PhoneBook();

    void addContact(const Contact &contact);
    Contact getContact(int index) const;
    int getSize() const;
};

#endif
