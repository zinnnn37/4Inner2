/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:09:38 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 11:18:09 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	AMateria* tmp;
	tmp = src->createMateria("icecure");

	ICharacter* me = new Character("me");
	ICharacter* bob = new  Character("bob");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	AMateria* tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	AMateria* tmp2 = src->createMateria("cure");
	me->equip(tmp);

	me->unequip(2);
	me->unequip(3);

	bob->equip(tmp1);
	bob->equip(tmp2);

	me->use(0, *bob);
	me->use(1, *bob);

	bob->use(0, *me);
	bob->use(1, *me);

	delete bob;
	delete me;
	delete src;

	return 0;
}