#include <cassert>
#include <iostream>
#include <sstream>
#include "../Contact.h"
#include "../PhoneBook.h"
#include "../utils.h"

void testContact()
{
    Contact contact;

    contact.setFirstName("Vinny");
    assert(contact.getFirstName() == "Vinny");

    contact.setLastName("Bass");
    assert(contact.getLastName() == "Bass");
}

void testPhoneBook()
{
    PhoneBook pb;
    Contact c1, c2;

    c1.setFirstName("Vinny");
    pb.addContact(c1);
    assert(pb.getSize() == 1);

    for (int i = 0; i < 9; i++)
    {
        Contact c;
        std::stringstream ss;
        ss << i;
        c.setFirstName("Test" + ss.str());
        pb.addContact(c);
    }
    assert(pb.getSize() == 8);

    Contact first = pb.getContact(0);
    assert(first.getFirstName() != "Vinny");
}

void testUtils()
{
    assert(formatColumn("test", 10) == "      test");
    assert(formatColumn("verylongtext", 10) == "verylongt.");
}

void testPhoneBookIntegration()
{
    PhoneBook pb;

    Contact c;
    c.setFirstName("Vinny");
    c.setLastName("Bass");
    c.setNickname("JD");
    c.setPhoneNumber("123456");
    c.setDarkestSecret("Likes pineapple on pizza");

    pb.addContact(c);

    Contact retrieved = pb.getContact(0);
    assert(retrieved.getFirstName() == "Vinny");
    assert(retrieved.getPhoneNumber() == "123456");

    std::stringstream output;
    displayContactList(pb, output);

    std::string expected = "|         0|      Vinny|       Bass|        JD|";
    assert(output.str().find(expected) != std::string::npos);
}

int main()
{
    testContact();
    testPhoneBook();
    testUtils();
    std::cout << "All unit tests passed!" << std::endl;

    testPhoneBookIntegration();
    std::cout << "All integration tests passed!" << std::endl;
    return 0;
}
