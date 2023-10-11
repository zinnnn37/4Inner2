/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:34:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 13:58:55 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	Base	*base;

	srand(time(NULL));

	base = generate();
	identify(base);
	identify(*base);

	delete base;

	return (0);
}
