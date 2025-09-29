#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

// Include ALL dependencies this header needs  
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <csignal>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		index;
	int		count;
	int		input_index;

public:
	PhoneBook();
	~PhoneBook();
	void AddFunction();
	void SearchFunction();
	bool IsValidIndex(std::string temp);
};

#endif