/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:34:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/15 14:16:09 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	leaks()
{
	system("leaks Base");
}

int	main(void)
{
	atexit(leaks);

	Base	*base;

	srand(time(NULL));

	base = generate();
	identify(base);
	identify(*base);

	delete base;

	std::cout << std::endl;

	return (0);
}
