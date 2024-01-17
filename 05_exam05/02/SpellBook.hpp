#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

class	ASpell;
class	ATarget;

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "ASpell.hpp"
#include "ATarget.hpp"

class	SpellBook
{
	private:
		typedef	std::map< std::string, ASpell * >	Map;
		typedef	std::pair< std::string, ASpell * >	Pair;
		typedef	Map::iterator						Iter;

		Map		_spells;

		SpellBook( const SpellBook& sb );

		SpellBook&	operator=( const SpellBook& sb );

	public:
		SpellBook();
		~SpellBook();

		void	learnSpell( ASpell* as );
		void	forgetSpell( const std::string& spell );
		ASpell*	createSpell( const std::string& spell );	
};

#endif