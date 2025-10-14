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

const std::string Harl::names[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
const Harl::Action Harl::actions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

void Harl::complain( std::string level )
{
	int var = -1;

	for (size_t i = 0; i < 4; i++)
	{
		if (names[i] == level)
			var = i;
	}
	switch (var)
	{
		case 0:
			(this->*actions[0])();
			/* fall through */
		case 1:
			(this->*actions[1])();
			/* fall through */
		case 2:
			(this->*actions[2])();
			/* fall through */
		case 3:
			(this->*actions[3])();
			break;
		default:
			std::cout << "invalid level" << std::endl;
	}
}