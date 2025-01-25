#include "Contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(const std::string &name)
{
    firstName = name;
}

void Contact::setLastName(const std::string &name)
{
    lastName = name;
}

void Contact::setNickname(const std::string &nick)
{
    nickname = nick;
}

void Contact::setPhoneNumber(const std::string &number)
{
    phoneNumber = number;
}

void Contact::setDarkestSecret(const std::string &secret)
{
    darkestSecret = secret;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}
