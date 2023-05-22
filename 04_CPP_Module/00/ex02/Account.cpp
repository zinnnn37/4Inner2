/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:24:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/22 18:49:08 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account()
{
	std::cout << "Account()" << std::endl;
}

Account::Account(int initial_deposit)
{
	std::cout << "Account(int)" << std::endl;
}

Account::~Account()
{
	std::cout << "~Account()" << std::endl;
}

void Account::_displayTimestamp()
{
	std::cout << "_displayTimestamp()" << std::endl;
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
	std::cout << "displayAccountsInfos()" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	std::cout << "makeDeposit()" << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	std::cout << "makeWithdrawal()" << std::endl;
}

int Account::checkAmount() const
{
	std::cout << "checkAmount()" << std::endl;
}

void Account::displayStatus() const
{
	std::cout << "displayStatus()" << std::endl;
}