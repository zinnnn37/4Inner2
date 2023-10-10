/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:54:28 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/10 17:04:56 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdint>

typedef struct	Data
{
	std::string	str;
	int			i;
};

class	Serializer
{
	private:
		uintptr_t	_ptr;

	public:
		Serializer();
		Serializer( const Serializer &s );
		~Serializer();

		Serializer	&operator=( const Serializer &s );

		static uintptr_t	serialize( Data* ptr );
		static Data			*deserialize( uintptr_t raw );
};

#endif