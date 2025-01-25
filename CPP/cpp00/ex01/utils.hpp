// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <ostream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

std::string getValidInput(const std::string &fieldName);
std::string formatColumn(const std::string &text, size_t width);
void addContact(PhoneBook &phoneBook);
void displayContactList(const PhoneBook &phoneBook, std::ostream &out = std::cout);
void searchContact(const PhoneBook &phoneBook);

#endif
