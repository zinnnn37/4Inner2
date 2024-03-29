/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:35:37 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/26 19:38:17 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <exception>

class	RPN
{
	private:
		std::string				_input;
		std::stack<int>			_rpn;
		std::stack<std::string>	_tmp;

		RPN();
		RPN( const RPN &r );

		RPN	&operator=( const RPN &rpn );

		bool	_isOp( char c );
		void	_split();
		void	_checkValid( std::string s );
		void	_calc();
		int		_doOp( int x, int y, char op );

	public:
		RPN( std::string input );
		~RPN();

		void	exec();
};

#endif