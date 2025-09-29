#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Initialize static member variables (required for static variables in C++)
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";amount:"
				<< initial_deposit
				<< ";created"
				<< std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";closed"
				<< std::endl;
}

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;

}

void Account::makeDeposit( int deposit )
{
	int	prev_amount = _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";p_amount:"
				<< prev_amount
				<< ";deposit:"
				<< deposit
				<< ";amount:"
				<< _amount
				<< ";nb_deposits:"
				<< _nbDeposits
				<< std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	int prev_amount = _amount;

	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout	<< "index:"
					<< _accountIndex
					<< ";p_amount:"
					<< prev_amount
					<< ";withdrawal:"
					<< "refused"
					<< std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";p_amount:"
				<< prev_amount
				<< ";withdrawal:"
				<< withdrawal
				<< ";amount:"
				<< _amount
				<< ";nb_withdrawals:"
				<< _nbDeposits
				<< std::endl;
	return true;
}

int Account::checkAmount( void ) const
{
	return _amount;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";deposits:"
				<< _nbDeposits
				<< ";withdrawals:"
				<< _nbWithdrawals
				<< std::endl;	
}

// setfill fills the field with 0 before the value requested for setw size
void Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0); //gets time
	std::tm* timeinfo = std::localtime(&now); //transform time in separate fields
	
	std::cout	<< "[" << (timeinfo->tm_year + 1900) //year field start from 1900 so it needs to be added
				<< std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1) //start at 0 in january so +1
				<< std::setfill('0') << std::setw(2) << timeinfo->tm_mday
				<< "_"
				<< std::setfill('0') << std::setw(2) << timeinfo->tm_hour
				<< std::setfill('0') << std::setw(2) << timeinfo->tm_min
				<< std::setfill('0') << std::setw(2) << timeinfo->tm_sec
				<< "] ";
}