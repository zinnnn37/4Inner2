/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:43:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 13:07:39 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

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

		void		getIdea( int idx ) const;
		std::string	setIdea( std::string idea );
};

#endif