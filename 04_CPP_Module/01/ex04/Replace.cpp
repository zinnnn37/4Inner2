/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:24:50 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/05 18:57:07 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

void	replace(
	std::ifstream& ifs, std::ofstream& ofs,
	std::string& s1, std::string& s2 )
{
	int	pos;
	int	len1;
	int	len2;

	std::string	line;
	
	len1 = s1.size();
	len2 = s2.size();

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
}