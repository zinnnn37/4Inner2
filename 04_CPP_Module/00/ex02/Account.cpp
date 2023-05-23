/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:24:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/23 16:30:41 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
	this->_displayTimestamp();
}

Account::Account(int initial_deposit)
{
	this->_displayTimestamp();
	
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	std::cout << "index:" << _nbAccounts << ";";
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	
	std::cout << "amount:" << initial_deposit << ";";
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	
	std::cout << "created" << std::endl;
	// 작업
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void Account::_displayTimestamp()
{
	time_t	time;
	char	buf[20];
	
	std::time(&time);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", localtime(&time));
	std::cout << buf;
}

int Account::getNbAccounts()
{
	std::cout << "getNbAccounts()" << std::endl;
}

int Account::getTotalAmount()
{
	std::cout << "getTotalAmount()" << std::endl;
}

int	Account::getNbDeposits()
{
	std::cout << "getNbDeposits()" << std::endl;
}

int Account::getNbWithdrawals()
{
	std::cout << "getNbWithdrawals()" << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << ";" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	this->_nbDeposits++;
	_totalNbDeposits++;

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposits:" << deposit << ";";
	this->_amount += deposit;
	_totalAmount += deposit;

	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";

	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::checkAmount() const
{
	std::cout << "checkAmount()" << std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
}