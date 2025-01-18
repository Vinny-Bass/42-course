#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();

    void setFirstName(const std::string &name);
    void setLastName(const std::string &name);
    void setNickname(const std::string &nick);
    void setPhoneNumber(const std::string &number);
    void setDarkestSecret(const std::string &secret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif
