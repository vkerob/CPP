#include"Account.hpp"
#include<iostream>
#include<iomanip>
#include<ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalAmount = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t current_time = std::time(NULL);
	std::tm	*time = std::localtime(&current_time);
	

	std::cout << "[" << time->tm_year + 1900 << std::setw(2) 
	<< std::setfill('0') << time->tm_mon + 1 << std::setw(2) 
	<< std::setfill('0') << time->tm_mday << "_" << std::setw(2) 
	<< std::setfill('0') << time->tm_hour << time->tm_min
	<< std::setw(2) << std::setfill('0') << time->tm_sec << "]";
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
	<< ";created" << std::endl;
	this->_amount = initial_deposit;
	return ;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
	<< ";closed" << std::endl;
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
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:"
	<< _totalAmount << ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;

}

void	Account::makeDeposit( int deposit )
{
	this->_totalNbDeposits += 1;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex  << ";p_amount:"
	<< this->_amount;
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount - withdrawal < 0)
	{
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex  << ";p_amount:"
		<< this->_amount << ":refused" << std::endl;
		return (1);
	}
	this->_totalNbWithdrawals += 1;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex  << ";p_amount:"
	<< this->_amount;
	this->_amount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal << ";amount:"
	<< this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals
	<< std::endl;
	return (0);
}

int		Account::checkAmount( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
	<< std::endl;
	return (1);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
	<< ";deposits:" <<_nbDeposits << ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}
