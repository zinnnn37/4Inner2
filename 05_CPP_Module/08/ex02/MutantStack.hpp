/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:52:21 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/23 16:27:35 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}

		MutantStack( const MutantStack &ms )
		{
			*this = ms;
		}

		~MutantStack() {}

		MutantStack &operator=( const MutantStack &ms )
		{
			if (this != &ms)
				*this = ms;
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator cbegin() const {return this->c.begin();}
		const_iterator cend() const {return this->c.end();}

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin() const {return this->c.rbegin();}
		const_reverse_iterator crend() const {return this->c.rend();}
};

#endif
