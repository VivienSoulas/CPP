#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

enum LoggerType
{
	IceType,
	CureType
};

class AMateria
{
	protected:
	std::string type;
	LoggerType	logType;

	public:
	AMateria();
	AMateria( std::string const & type );
	virtual ~AMateria() = 0;
	AMateria( const AMateria &other );
	AMateria &operator=( const AMateria &other );

	std::string const & getType() const;
	virtual void setType();
	LoggerType getLoggerType();

	void setLoggerType( LoggerType new_type );
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif