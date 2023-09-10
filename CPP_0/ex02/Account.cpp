#include"Account.hpp"
#include<iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalAmount = 0;

Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	return ;
}

Account::~Account( void )
{
	return ;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << _nbAccounts << ";total:"
	<< _totalAmount << ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_totalNbDeposits += 1;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_totalNbWithdrawals += 1;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;
}

int		Account::checkAmount( void ) const
{
	
}

void	Account::displayStatus( void ) const
{
	
}