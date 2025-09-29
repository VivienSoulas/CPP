#include "Contact.hpp"
// #include needed includes for this file

// constructor for class Contact, initialise the field of the class
Contact::Contact()
{
	FirstName = "";
	LastName = "";
	Nickname = "";
	PhoneNumber = "";
	DarkestSecret = "";
	std::cout << "Constructor Contact called, all field initialised to empty" << std::endl;
}

// destructor of the class Contact
Contact::~Contact()
{
	std::cout << "Destructor Contact called" << std::endl;
}

void Contact::AddFirstName()
{
	std::string temp;

	do
	{
		std::cout << "Type in your First Name:" << std::endl;
		getline(std::cin, temp);
	}	while (check_name(&temp) == 1);
	FirstName = temp;
}

void Contact::AddLastName()
{
	std::string temp;

	do
	{
		std::cout << "Type in your Last Name:" << std::endl;
		getline(std::cin, temp);
	}	while (check_name(&temp) == 1);
	LastName = temp;
}

void Contact::AddNickname()
{
	std::string temp;

	do
	{
		std::cout << "Type in your Nickname:" << std::endl;
		getline(std::cin, temp);
	}	while (check_input(&temp) == 1);
	Nickname = temp;
}

void Contact::AddPhoneNumber()
{
	std::string temp;
	
	do
	{
		std::cout << "Type in your Phone Number:" << std::endl;
		getline(std::cin, temp);
	}	while (check_number(&temp) == 1);
	PhoneNumber = temp;
}

void Contact::AddDarkestSecret()
{
	std::string temp;

	do
	{
		std::cout << "Type in your Darkest Secret:" << std::endl;
		getline(std::cin, temp);
	}	while (check_input(&temp) == 1);
	DarkestSecret = temp;
}

void Contact::DisplayFull(std::string input)
{
	std::cout << input << std::endl;
}

void Contact::DisplayPart(std::string input)
{
	int length = (int)input.length();

	if (length >= 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << input[i];
		std::cout << ".";
	}
	else
	{
		for (int i = 10; i > length; i--)
			std::cout << " ";
		std::cout << input;
	}
}

void Contact::DisplayAll()
{
	std::cout << std::endl;
	std::cout << std::setw(16) << std::right << "First Name: " << GetField(FIRST_NAME) << std::endl;
	std::cout << std::setw(16) << std::right << "Last Name: " << GetField(LAST_NAME) << std::endl;
	std::cout << std::setw(16) << std::right << "Nickname: " << GetField(NICKNAME) << std::endl;
	std::cout << std::setw(16) << std::right << "Phone Number: " << GetField(PHONE_NUMBER) << std::endl;
	std::cout << std::setw(16) << std::right << "Darkest Secret: " << GetField(DARKEST_SECRET) << std::endl;
	std::cout << std::endl;
}

// std::string Contact::GetField(int field)
// {
// 	if (field == FIRST_NAME)
// 		return (FirstName);
// 	else if (field == LAST_NAME)
// 		return (LastName);
// 	else if (field == NICKNAME)
// 		return (Nickname);
// 	else if (field == PHONE_NUMBER)
// 		return (PhoneNumber);
// 	else if (field == DARKEST_SECRET)
// 		return (DarkestSecret);
// 	else
// 		return ("");
// }

// other option for GetField:
std::string Contact::GetField(int index)
{
	switch (index)
	{
		case 0: return (FirstName);
		case 1: return (LastName);
		case 2: return (Nickname);
		case 3: return (PhoneNumber);
		case 4: return (DarkestSecret);
		default: return ("");
	}
}
