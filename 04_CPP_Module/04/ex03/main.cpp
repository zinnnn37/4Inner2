/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:09:38 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 12:30:29 by minjinki         ###   ########.fr       */
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
	const AMateria	*del = pat->getMateria(2);
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

	return 0;
}