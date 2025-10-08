#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void debug( void );
		void info ( void );
		void warning ( void );
		void error ( void );

	public:
		Harl();
		~Harl();
		void complain( std::string level );
		typedef void (Harl::*Action)();
		Harl::Action selectAction( std::string level );
		static const std::string names[];
		static const int levels[4];
		static const Action actions[];
	};
	
#endif