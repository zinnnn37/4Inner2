/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:47:02 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/05 18:56:32 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av)
{
	int				len1;
	int				len2;
	
	std::string		file;
	std::string		s1;
	std::string		s2;
	std::string		output;
	
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (ac != 4)
	{
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		return (1);
	}

	file = av[1];
	s1 = av[2];
	s2 = av[3];
	
	len1 = s1.size();
	len2 = s2.size();
	
	if (file.size() == 0)
	{
		std::cout << "Empty arguments" << std::endl;
		return (1);
	}
	if (len1 == 0)
		return (0);
	
	ifs.open(av[1]);
	if (ifs.fail())
	{
		std::cout << "Fail to open file" << std::endl;
		return (1);
	}
	
	output = av[1];
	output.append(".replace");
	ofs.open(output);
	if (ofs.fail())
	{
		std::cout << "Fail to open file.replace" << std::endl;
		return (1);
	}

	replace( ifs, ofs, s1, s2 );

	return (0);
}
