/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:46:53 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 13:19:24 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::_ptr = 0;

Serializer::Serializer() {}

Serializer::Serializer( const Serializer &s )
{
	(void)s;
}

Serializer::~Serializer() {}

Serializer&	Serializer::operator=( const Serializer &s )
{
	(void)s;
	return (*this);
}

uintptr_t	Serializer::serialize( Data *ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data *>(raw));
}
