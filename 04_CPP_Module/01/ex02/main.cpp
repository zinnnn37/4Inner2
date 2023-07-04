/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:21:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/04 14:12:39 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "Address:" << std::endl;
	std::cout << "str   : " << &string << std::endl;
	std::cout << "strPTR: " << &stringPTR << std::endl;
	std::cout << "strREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Content:" << std::endl;
	std::cout << "str   : " << string << std::endl;
	std::cout << "strPTR: " << stringPTR << std::endl;
	std::cout << "strREF: " << stringREF << std::endl;
	
	return (0);
}
