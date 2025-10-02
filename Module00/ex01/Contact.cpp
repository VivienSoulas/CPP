#include "Contact.hpp"

// constructor for class Contact, initialise the field of the class
Contact::Contact()
{
	FirstName = "";
	LastName = "";
	Nickname = "";
	PhoneNumber = "";
	DarkestSecret = "";
	//std::cout << "Constructor Contact called, all field initialised to empty" << std::endl;
}

// destructor of the class Contact
Contact::~Contact()
{
	//std::cout << "Destructor Contact called" << std::endl;
}

bool Contact::AddFirstName()
{
	bool eof = false;
	std::string temp;

	do
	{
		std::cout << "Type in your First Name:" << std::endl;
		if (!getline(std::cin, temp))
		{
			if (std::cin.eof())
			{
				eof = true;
				break;
			}
			std::cin.clear();
			continue;
		}
	}	while (check_name(&temp) == 1);
	FirstName = temp;
	return (eof);
}

bool Contact::AddLastName()
{
	bool eof = false;
	std::string temp;

	do
	{
		std::cout << "Type in your Last Name:" << std::endl;
		if (!getline(std::cin, temp))
		{
			if (std::cin.eof())
			{
				eof = true;
				break;
			}
			std::cin.clear();
			continue;
		}
	}	while (check_name(&temp) == 1);
	LastName = temp;
	return (eof);
}

bool Contact::AddNickname()
{
	bool eof = false;
	std::string temp;

	do
	{
		std::cout << "Type in your Nickname:" << std::endl;
		if (!getline(std::cin, temp))
		{
			if (std::cin.eof())
			{
				eof = true;
				break;
			}
			std::cin.clear();
			continue;
		}
	}	while (check_input(&temp) == 1);
	Nickname = temp;
	return (eof);
}

bool Contact::AddPhoneNumber()
{
	bool eof = false;
	std::string temp;
	
	do
	{
		std::cout << "Type in your Phone Number:" << std::endl;
		if (!getline(std::cin, temp))
		{
			if (std::cin.eof())
			{
				eof = true;
				break;
			}
			std::cin.clear();
			continue;
		}
	}	while (check_number(&temp) == 1);
	PhoneNumber = temp;
	return (eof);
}

bool Contact::AddDarkestSecret()
{
	bool eof = false;
	std::string temp;

	do
	{
		std::cout << "Type in your Darkest Secret:" << std::endl;
		if (!getline(std::cin, temp))
		{
			if (std::cin.eof())
			{
				eof = true;
				break;
			}
			std::cin.clear();
			continue;
		}
	}	while (check_input(&temp) == 1);
	DarkestSecret = temp;
	return (eof);
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
