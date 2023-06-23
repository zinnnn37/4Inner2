/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:47:02 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/23 13:08:37 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	int				pos;
	int				len;
	
	std::string		s1;
	std::string		s2;
	std::string		output;
	std::string		line;
	
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (ac != 4)
	{
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		return (1);
	}
	
	if (!*av[1] || !*av[2] || !*av[3])
	{
		std::cout << "Empty arguments" << std::endl;
		return (1);
	}
	
	s1 = av[2];
	s2 = av[3];
	
	// file open and null guard
	ifs.open(av[1]);
	if (ifs.fail())
	{
		std::cout << "Fail to open file" << std::endl;
		return (1);
	}
	
	// file open and null guard : filename에 .repace 추가
	output = av[1];
	output.append(".replace");
	ofs.open(output);
	if (ofs.fail())
	{
		std::cout << "Fail to open file.replace" << std::endl;
		return (1);
	}
	
	len = s1.size();
	while (getline(ifs, line))
	{
		pos = line.find(av[2]);

		if (pos > -1) {
			line.erase(pos, len);
			line.insert(pos, s2);
		}

		ofs << line << std::endl;
	}

	ifs.close();
	ofs.close();

	return (0);
}
