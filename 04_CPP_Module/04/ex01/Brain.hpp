/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:43:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 14:48:29 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class	Brain
{
	private:
		int			len;
		std::string	ideas[100];
	
	public:
		Brain();
		Brain( const Brain& brain );
		~Brain();

		Brain&	operator=( const Brain& brain );

		std::string	getIdea( int idx ) const;
		void		setIdea( std::string idea );
};

#endif