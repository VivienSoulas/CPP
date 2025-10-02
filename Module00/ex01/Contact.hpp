#ifndef CONTACT_HPP
#define CONTACT_HPP

# define FIRST_NAME 0
# define LAST_NAME 1
# define NICKNAME 2
# define PHONE_NUMBER 3
# define DARKEST_SECRET 4

// Include ALL dependencies this header needs
#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string PhoneNumber;
	std::string DarkestSecret;

public:
	Contact();
	~Contact();
	bool AddFirstName();
	bool AddLastName();
	bool AddNickname();
	bool AddPhoneNumber();
	bool AddDarkestSecret();
	// std::string GetField(int field);
	std::string GetField(int index);
	void DisplayFull(std::string input);
	void DisplayPart(std::string input);
	void DisplayAll();
};

int	check_input(std::string* input);
int	check_number(std::string* input);
int	check_name(std::string* input);

#endif