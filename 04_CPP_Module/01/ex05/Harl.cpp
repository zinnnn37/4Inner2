/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:36:47 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/23 15:58:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
}

Harl::~Harl( void )
{
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl << std::endl;

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-";
	std::cout << "pickle-special-ketchup burger. I really do!" << std::endl;
	
	std::cout << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl << std::endl;

	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;

	std::cout << std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl << std::endl;

	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here ";
	std::cout << "since last month." << std::endl;

	std::cout << std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl << std::endl;

	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	
	std::cout << std::endl << std::endl;
}

void	Harl::complain( std::string level )
{
	int		pos;
	void	(Harl::*f[4])( void )
			= { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	// Harl::*f[4]( void )
	// 1. 함수포인터 f는 Harl의 멤버함수를 사용하겠다고 명시 -> Harl::*f
	// 2. 배열 길이 4
	// 3. 함수들은 매개변수가 없다

	std::string	check = "0DEBUG1INFO2WARNING3ERROR";
	
	pos = check[check.find(level) - 1] - '0';
	
	if (pos >= 0)
		(this->*f[pos])();
	// 멤버함수는 객체를 통해서 사용해야함 >> 'this->'*f[]()
}
