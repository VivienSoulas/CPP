#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	temp;
	bool		running = true;
	while (running)
	{
		std::cout << "Please enter command: " << std::endl;
		if (!getline(std::cin, temp))
		{
			if (std::cin.eof()) // this handles ctl+d by catching the eof signal it sends
				break;
			std::cin.clear();
			continue;
		}
		if (temp == "ADD")
			phonebook.AddFunction();
		else if (temp == "SEARCH")
			phonebook.SearchFunction();
		else if (temp == "EXIT")
			running = false;
		else
			std::cout << "ERROR : Invalid command" << std::endl;
	}
	return (0);
}

// PhoneBook contructor, automatically call constructors of 8 Contact classes
PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
	input_index = 0;

	//std::cout << "Constructor PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	//std::cout << "Destructor PhoneBook called" << std::endl;
}

void PhoneBook::AddFunction()
{
	if (contacts[index].AddFirstName() == true)
		return ;
	if (contacts[index].AddLastName() == true)
		return ;
	if (contacts[index].AddNickname() == true)
		return ;
	if (contacts[index].AddPhoneNumber() == true)
		return ;
	if (contacts[index].AddDarkestSecret() == true)
		return ;
	index = (index + 1) % 8;
	if (count < 8)
		count++;
}

void PhoneBook::SearchFunction()
{
	std::string temp;
	bool eof = false;

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
		} while (IsValidIndex(temp) == false);
		if (eof == false)
			contacts[input_index].DisplayAll();
	}
	else
		std::cout << "ERROR : No contact available to show" << std::endl;
}

bool PhoneBook::IsValidIndex(std::string temp)
{
	if (temp.empty())
	{
		std::cout << "ERROR : invalid index" << std::endl;
		return (false);
	}
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