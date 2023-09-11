#include"Account.hpp"
#include<iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalAmount = 0;

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
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
	std::cout << "index:" << this->_accountIndex  << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_totalAmount -= withdrawal < 0)
		return (1);
	this->_totalNbWithdrawals += 1;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	std::cout << "index:" << this->_accountIndex  << ";p_amount:" << this->_amount;
	this->_amount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (0);
}

int		Account::checkAmount( void ) const
{
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << std::endl;
	return (1);
}

void	Account::displayStatus( void ) const
{
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" <<_nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
