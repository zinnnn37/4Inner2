/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:43:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/06 14:48:13 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

class	Brain
{
	private:
		std::string	ideas[100];
	
	public:
		Brain();
		Brain( const Brain& brain );
		~Brain();

		Brain&	operator=( const Brain& brain );
};

#endif