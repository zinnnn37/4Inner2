/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:24:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/22 19:04:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account()
{
	this->_displayTimestamp();
	std::cout << "Account()" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_displayTimestamp();
	std::cout << "Account(int)" << std::endl;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "~Account()" << std::endl;
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
	std::cout << "displayAccountsInfos()" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "makeDeposit()" << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "makeWithdrawal()" << std::endl;
}

int Account::checkAmount() const
{
	std::cout << "checkAmount()" << std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "displayStatus()" << std::endl;
}