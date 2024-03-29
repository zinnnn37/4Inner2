/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:11:50 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 19:25:19 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>	// or time.h?
#include <sstream>
#include <climits>

#define K 5

class	PmergeMe
{
	private:
		int					_ac;
		char				**_av;
		std::deque<int>		_dq;
		std::vector<int>	_vec;

		PmergeMe();

		void	_parse();
		void	_sort();

		bool	_checkValid( std::string buf );

		void	_sortDeque( int start, int end );
		void	_sortVector( int start, int end );

		void	_mergeDeque( int start, int mid, int end );
		void	_mergeVector( int start, int mid, int end );

		void	_insertDeque( int start, int end );
		void	_insertVector( int start, int end );

		void	_printBefore();
		void	_printAfter( double timeDeque, double timeVector );
		void	_printDeque();
		void	_printVector();

	public:
		PmergeMe( int ac, char **av );
		PmergeMe( const PmergeMe &pm );
		~PmergeMe();

		PmergeMe	&operator=( const PmergeMe &pm );
};

#endif