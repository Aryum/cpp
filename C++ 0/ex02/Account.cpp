/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 01:23:17 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/24 10:57:05 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// =================== (Cons/Desttructor ===================

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0; 
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount += initial_deposit;
	_nbDeposits = 0;
	
	//static
	_nbAccounts++;
	_totalAmount += initial_deposit;
	displayTimestamp();
	std::cout << 
	"index:" << _accountIndex << ";" <<
	"amount:" << _amount << ";" <<
	"created" << "\n";
}

Account::~Account(void)
{
	displayTimestamp();
	std::cout << 
	"index:" << _accountIndex << ";" <<
	"amount:" << _amount << ";" <<
	"closed" << "\n";
}

// =================== Static Methods ===================

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
	displayTimestamp();
	std::cout <<
	"accounts:" << _nbAccounts << ";" <<
	"total:" << _totalAmount << ";" <<
	"deposits:" << _totalNbDeposits << ";" <<
	"withdrawals:" << _totalNbWithdrawals << "\n";
}

void Account::displayTimestamp(void)
{
	time_t cur_sec = std::time(NULL);
	tm *cur_time = std::localtime(&cur_sec);
	std::cout << 
	"[" <<
	std::setfill('0') << std::setw(4) << 1900 + cur_time->tm_year <<
	std::setfill('0') << std::setw(2) << cur_time->tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << cur_time->tm_mday <<
	"_" <<
	std::setfill('0') << std::setw(2) << cur_time->tm_hour <<
	std::setfill('0') << std::setw(2) << cur_time->tm_min <<
	std::setfill('0') << std::setw(2) << cur_time->tm_sec <<
	"] ";
	
}

// =================== Public ===================

void Account::makeDeposit(int deposit)
{
	int last = _amount;
	
	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits ++;
	_totalNbDeposits++;
	
	displayTimestamp();
	std::cout << 
	"index:" << _accountIndex << ";" <<
	"p_amount:" << last << ";" <<
	"deposit:" << deposit << ";" <<
	"amount:" << _amount << ";" <<
	"nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	bool can_withdrawal = _amount > withdrawal;
	int last = _amount;

	displayTimestamp();
	std::cout << 
	"index:" << _accountIndex << ";" <<
	"p_amount:" << last << ";" <<
	"withdrawal:";
	if (can_withdrawal)
	{
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";" <<
		"amount:" << _amount << ";" <<
		"nb_withdrawals:" << _nbWithdrawals << "\n";
	}
	else
		std::cout << "refused" << "\n";
	return can_withdrawal;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	displayTimestamp();
	std::cout <<
	"index:" << _accountIndex << ";" <<
	"amount:" << _amount << ";" <<
	"deposits:" << _nbDeposits << ";" <<
	"withdrawals:" << _nbWithdrawals << "\n";
}

