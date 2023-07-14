/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:09:38 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 17:36:39 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <stdlib.h>

void	leaks()
{
	system("leaks Materia");
}

int	main(void)
{
	atexit(leaks);

	std::cout << CYAN"\n\n---------<< Basic Funcs >>---------\n" << WHITE << std::endl;
	/* Learn Materias */
	IMateriaSource* ms = new MateriaSource();
	ms->learnMateria(new Ice());
	ms->learnMateria(new Cure());
	ms->learnMateria(new Ice());
	ms->learnMateria(new Cure());

	/* Create Materias */
	AMateria* tmp;
	tmp = ms->createMateria("sth");

	/* create Characters */
	Character* pat = new Character("pat");
	Character* mat = new  Character("mat");

	/* Create and Equip */
	tmp = ms->createMateria("ice");
	pat->equip(tmp);
	delete tmp;

	tmp = ms->createMateria("cure");
	pat->equip(tmp);
	delete tmp;

	AMateria* tmp1 = ms->createMateria("ice");
	pat->equip(tmp1);
	AMateria* tmp2 = ms->createMateria("cure");
	pat->equip(tmp2);

	/* Unequip */
	pat->use(2, *mat);

	const AMateria	*del = pat->getMateria(2);
	pat->unequip(2);
	delete del;

	pat->equip(tmp2);
	pat->use(2, *mat);

	del = pat->getMateria(2);
	pat->unequip(2);
	delete del;

	del = pat->getMateria(3);
	pat->unequip(3);
	delete del;

	/* Equip and Use */
	mat->equip(tmp1);
	mat->equip(tmp2);

	pat->use(0, *mat);
	pat->use(1, *mat);
	mat->use(0, *pat);
	mat->use(1, *pat);

	/* delete */
	delete mat;
	delete pat;
	delete ms;
	delete tmp1;
	delete tmp2;

	std::cout << CYAN"----------<< Deep Copy >>----------\n" << WHITE << std::endl;

	Character*	ori = new Character("ori");
	AMateria*	ice = new Ice();

	ori->equip(ice);

	Character*	copy = new Character(*ori);

	delete ori;

	std::cout << CYAN"*** After delete ***\n" << std::endl;

	copy->use(0, *copy);

	delete copy;

	std::cout << CYAN"-----------------------------------\n" << WHITE << std::endl;

	Character	*c1 = new Character("c1");
	Character	*c2 = new Character("c2");

	c1->equip(ice);

	*c2 = *c1;

	delete c1;

	std::cout << CYAN"*** After delete ***\n" << std::endl;

	c2->use(0, *c2);

	delete ice;
	delete c2;

	return 0;
}