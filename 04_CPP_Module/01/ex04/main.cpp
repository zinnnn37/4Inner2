/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:47:02 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/05 11:46:21 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	int				pos;
	int				len1;
	int				len2;
	
	std::string		file;
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
	
	while (std::getline(ifs, line))
	{
		pos = 0;
		while (true) {
			pos = line.find(s1, pos);

			if (pos > -1) {
				line.erase(pos, len1);
				line.insert(pos, s2);
				pos += len2;
			}
			else
				break ;
		}

		ofs << line << std::endl;
	}

	ifs.close();
	ofs.close();

	return (0);
}
