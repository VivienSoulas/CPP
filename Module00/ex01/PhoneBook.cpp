#include "PhoneBook.hpp"
// more includes needed for this file

int	main()
{
	PhoneBook phonebook;
	std::string temp;

	do
	{
		std::cout << "Please enter command: " << std::endl;
		getline(std::cin, temp);
		if (temp == "ADD")
			phonebook.AddFunction();
		else if (temp == "SEARCH")
			phonebook.SearchFunction();
		else
			std::cout << "ERROR : Invalid command" << std::endl;
	} while (temp != "EXIT");
	return (0);
}

// PhoneBook contructor, automatically call constructors of 8 Contact classes
PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
	input_index = 0;

	std::cout << "Constructor PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Destructor PhoneBook called" << std::endl;
}

void PhoneBook::AddFunction()
{
	contacts[index].AddFirstName();
	contacts[index].AddLastName();
	contacts[index].AddNickname();
	contacts[index].AddPhoneNumber();
	contacts[index].AddDarkestSecret();
	index = (index + 1) % 8;
	if (count < 8)
		count++;
}

void PhoneBook::SearchFunction()
{
	std::string temp;

	if (count != 0)
	{
		std::cout << std::setw(10) << std::right << "Index" << "|" 
				  << std::setw(10) << std::right << "First Name" << "|" 
				  << std::setw(10) << std::right << "Last Name" << "|" 
				  << std::setw(10) << std::right << "Nickname" << std::endl;
		for (int i = 0; i < count; i++)
		{
			std::cout << std::setw(10) << std::right << i << "|";
			contacts[i].DisplayPart(contacts[i].GetField(FIRST_NAME));
			std::cout << "|";
			contacts[i].DisplayPart(contacts[i].GetField(LAST_NAME));
			std::cout << "|";
			contacts[i].DisplayPart(contacts[i].GetField(NICKNAME));
			std::cout << std::endl;
		}
		do
		{
			std::cout << "Select an index:";
			getline(std::cin, temp);
		} while (IsValidIndex(temp) == false);
		contacts[input_index].DisplayAll();
	}
	else
		std::cout << "ERROR : No contact available to show" << std::endl;
}

bool PhoneBook::IsValidIndex(std::string temp)
{
	for (int i = 0; i < (int)temp.length(); i++)
	{
		if (!isdigit(temp[i]))
		{
			std::cout << "ERROR : invalid index" << std::endl;
			return (false);
		}
	}
	input_index = atoi(temp.c_str());
	if (input_index < 0 || input_index >= count)
	{
		std::cout << "ERROR : invalid index" << std::endl;
		return (false);
	}
	return (true);
}