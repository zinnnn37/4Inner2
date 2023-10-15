/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:54:28 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 13:34:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

typedef struct	Data
{
	std::string	str;
	int			i;
}	Data;

class	Serializer
{
	private:
		static uintptr_t	_ptr;

		Serializer();
		Serializer( const Serializer &s );
		~Serializer();

	public:
		Serializer	&operator=( const Serializer &s );

		static uintptr_t	serialize( Data* ptr );
		static Data			*deserialize( uintptr_t raw );
};

#endif