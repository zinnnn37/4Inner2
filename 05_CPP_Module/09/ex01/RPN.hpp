/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:35:37 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 17:32:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <exception>

class	RPN:
{
	private:
		int					_len;
		std::string			_input;
		stack<int>			_rpn;
		stack<std::string>	_tmp;

		bool	_isOp( char c );
		void	_split();
		void	_checkValid();
		void	_calc();
		int		_doOp( int x, int y, char op );

	pubilc:
		RPN();
		RPN( std::string input );
		RPN( const RPN &r );
		~RPN();

		RPN	&operator=( const RPN &rpn );

		void	exec();
}

#endif