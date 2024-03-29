/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:13:03 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/15 14:12:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	leaks()
{
	system("leaks serializer");
}

int	main(void)
{
	atexit(leaks);

	Data		*data = new Data;
	uintptr_t	raw;

	data->str = "string";
	data->i = 42;

	std::cout << "---------- before serialization ----------\n" << std::endl;

	std::cout << "data->str:\t" << data->str << std::endl;
	std::cout << "data->i:\t" << data->i << std::endl;

	std::cout << "\n---------- after serialization -----------\n" << std::endl;
	
	raw = Serializer::serialize(data);
	std::cout << "raw:\t" << raw << std::endl;

	std::cout << "\n--------- after deserialization ----------\n" << std::endl;

	data = Serializer::deserialize(raw);
	std::cout << "data->str:\t" << data->str << std::endl;
	std::cout << "data->i:\t" << data->i << std::endl << std::endl;

	delete data;

	return (0);
}