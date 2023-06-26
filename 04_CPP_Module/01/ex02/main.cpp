/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:21:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/26 11:56:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string& strREF = str;

	std::cout << "Address:" << std::endl;
	std::cout << "str   : " << &str << std::endl;
	std::cout << "strPTR: " << &strPTR << std::endl;
	std::cout << "strREF: " << &strREF << std::endl << std::endl;

	std::cout << "Content:" << std::endl;
	std::cout << "str   : " << str << std::endl;
	std::cout << "strPTR: " << strPTR << std::endl;
	std::cout << "strREF: " << strREF << std::endl;
	
	return (0);
}

// PTR: str의 주소값을 담고 있는 공간
// REF: str 그 자체, 단지 이름만 다를 뿐