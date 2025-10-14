#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::debug( void )
{
	std::cout	<< "DEBUG\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
				<< std::endl;
}

void Harl::info( void )
{
	std::cout	<< "INFO\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void Harl::warning( void )
{
	std::cout	<< "WARNING\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
				<< std::endl;
}

void Harl::error( void )
{
	std::cout	<< "ERROR\nThis is unacceptable! I want to speak to the manager now."
				<< std::endl;
}


const std::string Harl::names[] = { "debug", "info", "warning", "error" };
const Harl::Action Harl::actions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };


// finding pointers to member functions
void Harl::complain( std::string level )
{
	void (Harl::*action)();

	action = selectAction(level);
	if (action)
		(this->*action)();
	else
		std::cout << "Incompatible level input" << std::endl;
}

// mapping names vs actions
Harl::Action Harl::selectAction( std::string level )
{
	for (size_t i = 0; i < 4; i++)
	{
		if (level == names[i])
		{
			return (actions[i]);
		}
	}
	return (NULL);
}



// Also possible : creating an object and calling it directly without "this"
// void Harl::complain( std::string level )
// {
// 	Harl h;
// 	void (Harl::*action)();

// 	action = selectAction(level);
// 	if (action)
// 		(h.*action)();
// 	else
// 		std::cout << "Incompatible level input" << std::endl;
// }



// easy with switch
// void Harl::complain( std::string level )
// {
// 	int var = -1;

// 	for (size_t i = 0; i < 4; i++)
// 	{
// 		if (names[i] == level)
// 			var = i;
// 	}
// 	switch (var)
// 	{
// 		case 0:
// 			(this->*actions[0])();
// 			break ;
// 		case 1:
// 			(this->*actions[1])();
// 			break ;
// 		case 2:
// 			(this->*actions[2])();
// 			break ;
// 		case 3:
// 			(this->*actions[3])();
// 			break;
// 		default:
// 			std::cout << "invalid level" << std::endl;
// 	}
// }



// for better understanding of pointer to member function:
// void Harl::complain( std::string level )
// {
// 	if (level == "debug")
// 	{
// 		void (Harl::*ptrToMemberFunc)() = &Harl::debug;
// 		(this->*ptrToMemberFunc)();
// 	}
// 	else if (level == "info")
// 	{
// 		void (Harl::*ptrToMemberFunc)() = &Harl::info;
// 		(this->*ptrToMemberFunc)();
// 	}
// 	else if (level == "warning")
// 	{
// 		void (Harl::*ptrToMemberFunc)() = &Harl::warning;
// 		(this->*ptrToMemberFunc)();
// 	}
// 	else if (level == "error")
// 	{
// 		void (Harl::*ptrToMemberFunc)() = &Harl::error;
// 		(this->*ptrToMemberFunc)();
// 	}
// }