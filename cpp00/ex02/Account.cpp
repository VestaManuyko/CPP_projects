#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:"
	<< _totalAmount << ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
Account::Account(int initial_deposit)
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex 
	<< ";amount:" << this->_amount << ";created\n";
	this->makeDeposit(initial_deposit);
	this->_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}
Account::Account(void)
{
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex 
	<< ";amount:" << this->_amount << ";closed\n";
}

void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > this->_amount)
	{
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount << ";withdrawal:refused\n";
		return false;
	}
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount;
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex 
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t  timestamp;
    std::tm      *t;
    char         buffer[20];
	
    if (std::time(&timestamp) == (std::time_t)(-1))
	return ;
    t = std::localtime(&timestamp);
    if (t == NULL)
	return ;
    if (std::strftime(buffer, 20, "%Y%m%d_%H%M%S", t) == 0)
	return ;
    std::cout << "[" << buffer << "]";
}
