#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int		Account::getTotalAmount(void) {
	return (_totalAmount);
}

int		Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';'
			<< "total:" << getTotalAmount() << ';'
			<< "deposits:" << getNbDeposits() << ';'
			<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _nbAccounts++ << ';'
			<< "amount:" << initial_deposit << ';'
			<< "created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			<< "amount:" << _amount << ';'
			<< "closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			<< "p_amount:" << p_amount << ';'
			<< "deposit:" << deposit << ';'
			<< "amount:" << _amount << ';'
			<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int	p_amount;

	p_amount = _amount;
	_amount -= withdrawal;
	if (checkAmount() == false) {
		_amount  = p_amount;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ';'
				<< "p_amount:" << p_amount << ';'
				<< "withdrawal:refused" << std::endl;
		return (false);
	}
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			<< "p_amount:" << p_amount << ';'
			<< "withdrawal:" << withdrawal << ';'
			<< "amount:" << _amount << ';'
			<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount(void) const {
	if (_amount < 0)
		return (false);
	return (true);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			<< "amount:" << _amount << ';'
			<< "deposits:" << _nbDeposits << ';'
			<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {
	std::time_t	timer;
	std::tm		*timeinfo;
	char		buffer[20];

	timer = std::time(nullptr);
	timeinfo = std::localtime(&timer);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << buffer;
}

Account::Account(void) {
	std::cout << "default constructor" << std::endl;
}