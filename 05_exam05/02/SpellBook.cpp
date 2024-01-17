#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook( const SpellBook& sb )
{
	*this = sb;
}

SpellBook::~SpellBook() {}

SpellBook&	SpellBook::operator=( const SpellBook& sb )
{
	(void)sb;

	return (*this);
}

void	SpellBook::learnSpell( ASpell *as )
{
	SpellBook::Iter	it = this->_spells.find(as->getName());

	if (it == this->_spells.end())
		this->_spells.insert( SpellBook::Pair(as->getName(), as) );
}

void	SpellBook::forgetSpell( const std::string& spell )
{
	SpellBook::Iter	it = this->_spells.find(spell);

	if (it != this->_spells.end())
	{
		this->_spells.erase(spell);
		delete it->second;
	}
}

ASpell*	SpellBook::createSpell( const std::string& spell )
{
	SpellBook::Iter	it = this->_spells.find(spell);

	if (it != this->_spells.end())
		return (it->second->clone());
	
	return (NULL);
}