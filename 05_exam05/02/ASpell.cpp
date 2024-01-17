#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell( std::string name, std::string effects )
	: _name(name), _effects(effects)
{
}

ASpell::ASpell( const ASpell &a )
{
	*this = a;
}

ASpell::~ASpell() {}

ASpell&	ASpell::operator=( const ASpell& as )
{
	if (this != &as)
	{
		this->_name = as.getName();
		this->_effects = as.getEffects();
	}

	return (*this);
}

std::string	ASpell::getName() const
{
	return (this->_name);
}

std::string	ASpell::getEffects() const
{
	return (this->_effects);
}

void	ASpell::launch( const ATarget& at ) const
{
	at.getHitBySpell(*this);
}